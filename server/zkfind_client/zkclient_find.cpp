#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include "zkclient_find.h"

ItrPathVec itr_path;
ItrNodeMap itr_nodemap;

static pthread_rwlock_t   S_Lock = PTHREAD_RWLOCK_INITIALIZER;

void ZkCallBackFun::findWatcherFn(zhandle_t* zh, int type, int state, const char* path, void* watcherCtx)
{
    ZkClient* zkc = static_cast<ZkClient*>(watcherCtx);

    if(type == ZOO_SESSION_EVENT)
    {
        if( state == ZOO_CONNECTED_STATE )
        {
            zkc->setConnectStatus(true);
        }
        else if( state == ZOO_EXPIRED_SESSION_STATE )
        {  
            zkc->reConnect();
        }
        else if( state == ZOO_AUTH_FAILED_STATE )
        {
            LOG_ERROR(("findWatcherFn ZOO_AUTH_FAILED_STATE"));
        }
    }
/*    else if(type == ZOO_CREATED_EVENT)
    {
        LOG_ERROR(("findWatcherFn: ZOO_CREATED_EVENT creat [%s] succuss",path));
        zkc->reWatchPathAsync(string(path));
    }
    else if(type == ZOO_DELETED_EVENT)
    {
        LOG_ERROR(("findWatcherFn: ZOO_CHANGED_EVENT node value [%s] has delete",path));
    }
    else if(type == ZOO_CHANGED_EVENT)
    {
        zkc->reWatchPathAsync(string(path));
        LOG_ERROR(("findWatcherFn: ZOO_CHANGED_EVENT node value [%s] children change",path));
    }*/
    else if(type == ZOO_CHILD_EVENT)
    {
        zkc->reWatchPathAsync(string(path));
        LOG_ERROR(("findWatcherFn: ZOO_CHILD_EVENT path=[%s] children has change",path));
    }
    else
    {
            LOG_ERROR(("findWatcherFn: type = %d, state = %d",type, state));
    }

}

void ZkCallBackFun::stringCompletionPathCall(int rc, const struct String_vector *strings, const void *data)
{
    if(data == NULL)
        return;

    CallbackData* cllbckdt = static_cast<CallbackData*>(const_cast<void *>(data));
    string path = cllbckdt->data;
    ZkClient* zkc = static_cast<ZkClient*>(cllbckdt->ctx);
    delete cllbckdt;
    switch(rc)
    {
        case ZOK:
            {
                LOG_ERROR(("stringCompletionPathCall:watch node:[%s] success, node count:%d ",path.c_str(),strings->count));
                vector<string> vec;
                vec.clear();

                for (int i = 0; i < strings->count; i++)
                {
                    vec.push_back(strings->data[i]);
                }
                zkc->setMapNodeInfo(path, vec);
            }
            break;
        case ZNONODE:
                LOG_ERROR(("stringCompletionPathCall: path[%s]  has no exist, rc:%d ",path.c_str(),rc));                
            break;
        case ZCONNECTIONLOSS:
                zkc->reWatchPathAsync(path);
            break;
        case ZOPERATIONTIMEOUT:
                zkc->reConnect();
            break;
        default:
                LOG_ERROR(("stringCompletionPathCall: path = %s, rc=%d", path.c_str(), rc));
            break; 
    }

} 

ZkClient::ZkClient():_M_strZkCluster(""),_M_nSessTimeout(4000),_M_eConnState(false),_M_pZkHandle(NULL)
{

}

ZkClient::~ZkClient()
{
    if(_M_pZkHandle)
    {
        zookeeper_close(_M_pZkHandle);
        _M_pZkHandle = NULL;
    }

    _M_eConnState = false;
    _M_mNode.clear();
    _M_vPath.clear();
}

bool ZkClient::init(const string& zkCluster,int sessTimeout)
{
    _M_strZkCluster = zkCluster;
    _M_nSessTimeout = sessTimeout > _M_nSessTimeout?sessTimeout:_M_nSessTimeout;

    _M_pZkHandle = zookeeper_init(_M_strZkCluster.c_str(), &ZkCallBackFun::findWatcherFn, _M_nSessTimeout, 0, this, 0); 
    zoo_set_debug_level(ZOO_LOG_LEVEL_INFO);

    int cnt = 2000;
    do
    {
        usleep(1000);
        if( _M_eConnState)
            return true;
    } while ( --cnt != 0);

    return false;
}

void ZkClient::reConnect()
{
    _M_eConnState = false;
     
    if(_M_pZkHandle)
    {
        zookeeper_close(_M_pZkHandle);
        _M_pZkHandle = NULL; 
    }

    _M_pZkHandle = zookeeper_init(_M_strZkCluster.c_str(), &ZkCallBackFun::findWatcherFn, _M_nSessTimeout, 0, this, 0);

    int cnt = 2000;
    do
    {
        usleep(1000);
        if(_M_eConnState)
            reWatchPathMultAsync();
    }while ( --cnt != 0);

}

void ZkClient::setConnectStatus(bool status)
{
    _M_eConnState = status;
}

bool ZkClient::getConnectStatus()
{
    return _M_eConnState;
}

bool ZkClient::findPathInfo(const string& path)
{
    itr_path=find(_M_vPath.begin(),_M_vPath.end(),path);
    if( itr_path != _M_vPath.end())
        return true;
    
    return false;
}

void ZkClient::setMapNodeInfo(const string& path,vector<string>& vec)
{
    if(path.empty())
        return;
    string::size_type pos = path.find_last_of('/');
    string pathname = path.substr(0, pos);
    string nodename = path.substr(pos + 1);
    if(nodename.empty())
        return;

    MutexGuard wlock(&S_Lock, true);

    itr_nodemap=_M_mNode.find(nodename);
    if( itr_nodemap!=_M_mNode.end() )
    {
        itr_nodemap->second=vec;
    }
    else
    {
        _M_mNode.insert( pair<string,vector<string> >(nodename,vec) );
    }
}

string ZkClient::getMapNodeInfo(const string& service)
{
    string defval="";
    if(service.empty())
        return defval;
    
    MutexGuard rlock(&S_Lock, false);

    itr_nodemap=_M_mNode.find(service);
    if( (itr_nodemap==_M_mNode.end())||(0==itr_nodemap->second.size()) )
        return defval;

    int n = getRandom();
    int idx = n % itr_nodemap->second.size();
    defval=itr_nodemap->second[idx];
    LOG_ERROR(("getMapNodeInfo: service= %s, value=%s", service.c_str(), defval.c_str()));
    
    return defval;   
}

int ZkClient::getRandom()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand((int)tv.tv_usec);
    int num = rand();
    return num;
}

int ZkClient::firstWatchPathAsync(const string& path)
{
    if(path.empty())
    {
        LOG_ERROR(("The path can't be empty"));
        return -1;
    }

    if( findPathInfo(path) )
    {
        LOG_ERROR(("The path is registered"));
        return -1;
    }

    _M_vPath.push_back(path);
    reWatchPathAsync(path);
    return 0;
}

int ZkClient::reWatchPathAsync(const string& path)
{
    CallbackData* ctx = new CallbackData(path, this);

    int rc = zoo_awget_children(_M_pZkHandle, path.c_str(), &ZkCallBackFun::findWatcherFn, this, &ZkCallBackFun::stringCompletionPathCall, ctx);   
    if(ZOK != rc)
    {
        LOG_ERROR(("awget_children failed, path: %s, rc = %d",path.c_str(), rc));
        return 0;
    }

    return 1;
}

int ZkClient::reWatchPathMultAsync()
{
     if( _M_vPath.empty() )
        return 0;

     int n=_M_vPath.size();
     for(size_t i=0; i<n; i++)
     {
        reWatchPathAsync(_M_vPath[i]);
     }

     return 1;
}
