#ifndef _ZKCLIENT_MULTIREG_H_
#define _ZKCLIENT_MULTIREG_H_
#include <stddef.h>
#include <signal.h>
#include <utility>
#include<map>
#include<string>

#include "zookeeper/zookeeper.h"
#include "zookeeper/zookeeper_log.h"

using std::string;
using std::map;
using std::pair;

struct CallbackData
{
    CallbackData(const string& d,void* p):data(d), ctx(p){}
    CallbackData(const char* d,void* p):data(d), ctx(p){}
    string data;
    void* ctx;
};

enum ConnectionState{ZKC_CLOSED_STATE = 0, ZKC_CONNECTED_STATE , ZKC_EXPIRED_STATE};

typedef map<string, string> _ZK_MAP;
typedef map<string, string>::iterator _ZK_ITR;

class ZkCallBackFun
{
public:
    static void mainWatcherFn(zhandle_t *zh, int type, int state, const char *path,void *content);

    static void stringCompletionCallBack(int rc, const char *value, const void *data);               

    static void stateCompletion(int rc, const struct Stat *stat, const void *data);
};

class ZkClient
{
public:
    ZkClient();

    ~ZkClient();

    bool init( const string& zkCluster,int sessTimeout = 0);

    void reConnect();

    void setConnectStatus(enum  ConnectionState status);

    enum ConnectionState getConnectStatus();

public:
    int regPathNode(const string& path, const string& value = "");

    int creatPathNodeAsync(const string& path, const string& value);

    int watchPathNodeAsync(const char* path);

    bool findNodeInfo(const string& path, string value = "");

    int reRegPathMultNode();

private:
    _ZK_MAP          _M_map;
    string           _M_strZkCluster;
    int              _M_nSessTimeout;
    ConnectionState  _M_eConnState;
    zhandle_t*       _M_ptrZkHandle;

};

#endif