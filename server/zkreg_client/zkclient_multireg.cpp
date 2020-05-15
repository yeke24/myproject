#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include "zkclient_multireg.h"

_ZK_ITR itr;

void ZkCallBackFun::mainWatcherFn(zhandle_t* zh, int type, int state, const char* path, void* watcherCtx)
{
    ZkClient* zkc = static_cast<ZkClient*>(watcherCtx);

    if(type == ZOO_SESSION_EVENT)
    {
        if( state == ZOO_CONNECTED_STATE )
        {
            zkc->setConnectStatus(ZKC_CONNECTED_STATE);
            zkc->reRegPathMultNode();
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
/*    else if(type == ZOO_NOTWATCHING_EVENT)
    {
        zkc->watchPathNodeAsync(path);
        LOG_ERROR(("mainWatcherFn: ZOO_NOTWATCHING_EVENT node value [%s] wacth has loss",path));

    }*/
    else if(type == ZOO_DELETED_EVENT)
    {
        string value="";
        if( zkc->findNodeInfo(string(path),value) )
        {
            zkc->creatPathNodeAsync(string(path),value);
        }

    }
    else
    {
            LOG_ERROR(("mainWatcherFn: type = %d, state = %d",type, state));

    }

}

void ZkCallBackFun::stringCompletionCallBack(int rc, const char *value, const void *data)
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

void ZkCallBackFun::stateCompletion(int rc, const struct Stat *stat, const void *data)
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
			    string value="";
		        if( zkc->findNodeInfo(string(path),value) )
		        {
		            zkc->creatPathNodeAsync(string(path),value);
		        }
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

ZkClient::ZkClient():_M_strZkCluster(""),_M_nSessTimeout(4000),_M_eConnState(ZKC_CLOSED_STATE),_M_ptrZkHandle(NULL)
{

}

ZkClient::~ZkClient()
{
	if(_M_ptrZkHandle)
	{
		zookeeper_close(_M_ptrZkHandle);
		_M_ptrZkHandle = NULL;
	}

	_M_eConnState = ZKC_CLOSED_STATE;
	_M_map.clear();
}

bool ZkClient::init(const string& zkCluster,int sessTimeout)
{
	_M_strZkCluster = zkCluster;
    _M_nSessTimeout = sessTimeout > _M_nSessTimeout?sessTimeout:_M_nSessTimeout;

    _M_ptrZkHandle = zookeeper_init(_M_strZkCluster.c_str(), &ZkCallBackFun::mainWatcherFn, _M_nSessTimeout, 0, this, 0); 
    zoo_set_debug_level(ZOO_LOG_LEVEL_INFO);

    int cnt = 2000;
	do
	{
		usleep(1000);
		if ( ZKC_CONNECTED_STATE== _M_eConnState)
			return true;
	} while ( --cnt != 0);

    return false;
}

void ZkClient::reConnect()
{
    setConnectStatus(ZKC_CLOSED_STATE);

    if(_M_ptrZkHandle)
    {
        zookeeper_close(_M_ptrZkHandle);
        _M_ptrZkHandle = NULL;        
    }

    _M_ptrZkHandle = zookeeper_init(_M_strZkCluster.c_str(), &ZkCallBackFun::mainWatcherFn, _M_nSessTimeout, 0, this, 0);
}

void ZkClient::setConnectStatus(enum  ConnectionState status)
{
	_M_eConnState = status;
}

enum ConnectionState ZkClient::getConnectStatus()
{
    return _M_eConnState;
}

bool ZkClient::ZkClient::findNodeInfo(const string& path, string value)
{
    itr=_M_map.find(path);
    if( itr != _M_map.end())
    {
    	value=itr->second;
        return true;
    }
    
    return false;
}

int ZkClient::regPathNode(const string& path, const string& value)
{
    if(path.empty())
    {
        LOG_ERROR(("The path can't be empty"));
        return -1;
    }

    if( _M_map.find(path) != _M_map.end())
    {
        LOG_ERROR(("The path is registered"));
        return -1;
    }

    _M_map.insert( pair<string, string>(path, value) ); 
    creatPathNodeAsync(path, value);
    return 0;
}

int ZkClient::watchPathNodeAsync(const char* path)
{
    CallbackData* ctx = new CallbackData(path, this);
    return zoo_awexists(_M_ptrZkHandle , path, &ZkCallBackFun::mainWatcherFn, this, &ZkCallBackFun::stateCompletion, ctx);
}

int ZkClient::creatPathNodeAsync(const string& path, const string& value)
{
    CallbackData* ctx = new CallbackData(path, this);
    return zoo_acreate(_M_ptrZkHandle, path.c_str(), value.c_str(), value.length(), &ZOO_OPEN_ACL_UNSAFE, ZOO_EPHEMERAL, &ZkCallBackFun::stringCompletionCallBack, ctx);  
}

int ZkClient::reRegPathMultNode()
{
     if( _M_map.empty() )
     	return 0;

 	for( itr=_M_map.begin(); itr!=_M_map.end(); itr++)
 	{
 		creatPathNodeAsync(itr->first,itr->second);
 	}

     return 1;
}
