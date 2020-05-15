#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include "zookeeper/zookeeper.h"
#include "zookeeper/zookeeper_log.h"
#include "zktest.h"

void zk_keke_watcher_g(zhandle_t* zh, int type, int state, const char* path, void* watcherCtx)
{
    ZkClient* zkc = static_cast<ZkClient*>(watcherCtx);

    if(type == ZOO_SESSION_EVENT)
    {
        if( state == ZOO_CONNECTED_STATE )
        {
            zkc->setConnectStatus(ZKC_CONNECTED_STATE);
            zkc->reRegPathNodeVec();
        }
        else if( state == ZOO_EXPIRED_SESSION_STATE )
        {  
            zkc->reConnect();     
        }
        else if( state == ZOO_AUTH_FAILED_STATE )
        {
            LOG_ERROR(("ZOO_AUTH_FAILED_STATE"));
        }
    }
    else if(type == ZOO_CREATED_EVENT)
    {
        LOG_ERROR(("mainWatcherFn: ZOO_CREATED_EVENT creat [%s] succuss",path));
        zkc->watchPathNodeAsync(path);
    }
    else if(type == ZOO_CHANGED_EVENT)
    {
        zkc->watchPathNodeAsync(path);
        LOG_ERROR(("mainWatcherFn: ZOO_CHANGED_EVENT node value [%s] change",path));

    }
    else if(type == ZOO_DELETED_EVENT)
    {
        ZkClient::node_size_type pos = zkc->findNodeInfo(string(path));
        if(pos != ZkClient::nopos)
        {
            NodeInfo& ni = zkc->getNodeInfo(pos);
            zkc->creatPathNodeAsync(ni._M_strPath, ni._M_strValue);
        }
    }
    else
    {
            LOG_ERROR(("mainWatcherFn: type = %d, state = %d",type, state));
    }

}

void stringCompletionCallBack(int rc, const char *value, const void *data)
{
    CallbackData* cllbckdt = static_cast<CallbackData*>(const_cast<void *>(data));
    string path = cllbckdt->data;
    ZkClient* zkc = static_cast<ZkClient*>(cllbckdt->ctx);
    delete cllbckdt;
    switch(rc)
    {
        case ZOK:
            LOG_ERROR(("stringCompletionCallBack: create node [%s] success",path.c_str()));
        case ZNODEEXISTS:
        case ZCONNECTIONLOSS: 
                zkc->watchPathNodeAsync(path.c_str());
            break;
        case ZOPERATIONTIMEOUT:
                zkc->reConnect();
            break;
        default:
            LOG_ERROR(("stringCompletionCallBack:rc=%d, path = %s",rc, value));
            break;
    }

}   

void stateCompletion(int rc, const struct Stat *stat, const void *data)
{
    CallbackData* cllbckdt = static_cast<CallbackData*>(const_cast<void *>(data));
    string path = cllbckdt->data;
    ZkClient* zkc = static_cast<ZkClient*>(cllbckdt->ctx);
    delete cllbckdt;
    switch(rc)
    {
        case ZOK:
                LOG_ERROR(("stateCompletion:watch node:[%s] success",path.c_str()));
            break;
        case ZNONODE:
            {
                ZkClient::node_size_type pos = zkc->findNodeInfo(path);
                if(pos != ZkClient::nopos)
                    zkc->creatPathNodeAsync(zkc->getNodeInfo(pos)._M_strPath, zkc->getNodeInfo(pos)._M_strValue);
            }
            break;
        case ZCONNECTIONLOSS:
            zkc->watchPathNodeAsync(path.c_str());
            break;
        case ZOPERATIONTIMEOUT:
            zkc->reConnect();
            break;
        default:
            LOG_ERROR(("stringCompletionCallBack:rc=%d, path = %s",rc, path.c_str()));
            break; 
    }   

}


ZkClient::ZkClient():_M_nSessTimeout(3000),_M_ptrZkHandle(NULL)
{
    setConnectStatus(ZKC_CLOSED_STATE);
}
ZkClient::~ZkClient()
{
    zookeeper_close(_M_ptrZkHandle);    
    setConnectStatus(ZKC_CLOSED_STATE);  
}

void ZkClient::init( const string& zkCluster, int sessTimeout)
{
    _M_strZkCluster = zkCluster;
    _M_nSessTimeout = sessTimeout > _M_nSessTimeout?sessTimeout:_M_nSessTimeout;

    _M_ptrZkHandle = zookeeper_init(_M_strZkCluster.c_str(), zk_keke_watcher_g, _M_nSessTimeout, 0, this, 0); //
    zoo_set_debug_level(ZOO_LOG_LEVEL_INFO);
}

void ZkClient::reConnect()
{
    setConnectStatus(ZKC_CLOSED_STATE);
    zookeeper_close(_M_ptrZkHandle);
    _M_ptrZkHandle = NULL;
    _M_ptrZkHandle = zookeeper_init(_M_strZkCluster.c_str(), zk_keke_watcher_g, _M_nSessTimeout, 0, this, 0);
}

void ZkClient::setConnectStatus(enum  ConnectionState status)
{
    _M_eConnState = status;
}

enum ConnectionState ZkClient::getConnectStatus()
{
    return _M_eConnState;
}

int ZkClient::regPathNode(const string& path, const string& value)
{

    if(path.empty())
    {
        LOG_ERROR(("The path can't be empty"));
        return -1;
    }

    for(vector<NodeInfo>::const_iterator itr = _M_regNodeVec.begin(); itr != _M_regNodeVec.end(); ++itr)
    {
        if(itr->_M_strPath == path)
        {
            LOG_ERROR(("The path is registered"));
            return -1;
        }
    }
    _M_regNodeVec.push_back(NodeInfo(path, value));
    LOG_ERROR(("%s--",_M_regNodeVec[0]._M_strPath.c_str()));
    creatPathNodeAsync(path, value);
    return 0;
}

int ZkClient::creatPathNodeAsync(const string& path, const string& value)
{
    CallbackData* ctx = new CallbackData(path, this);
    //ZOO_OPEN_ACL_UNSAFE 无acl 
    //ZOO_EPHEMERAL 临时节点 默认0为：永久无序节点 
    return zoo_acreate(_M_ptrZkHandle, path.c_str(), value.c_str(), value.length(), &ZOO_OPEN_ACL_UNSAFE, ZOO_EPHEMERAL, stringCompletionCallBack, ctx);  
}

int ZkClient::watchPathNodeAsync(const char* path)
{
    CallbackData* ctx = new CallbackData(path, this);
    return zoo_awexists(_M_ptrZkHandle , path, zk_keke_watcher_g, this, stateCompletion, ctx);
}

ZkClient::node_size_type ZkClient::findNodeInfo(const string& path)
{
    for(node_size_type i = 0; i < _M_regNodeVec.size(); ++i)
    {
        if( _M_regNodeVec[i]._M_strPath == path)
            return i;
    }
    return nopos;
}

NodeInfo& ZkClient::getNodeInfo(node_size_type idx)
{
    return _M_regNodeVec[idx];
}

int ZkClient::reRegPathNodeVec()
{
     for(vector<NodeInfo>::size_type i = 0; i < _M_regNodeVec.size(); ++i)
     {
         creatPathNodeAsync(_M_regNodeVec[i]._M_strPath,_M_regNodeVec[i]._M_strValue);
     }
     return 0;
}
