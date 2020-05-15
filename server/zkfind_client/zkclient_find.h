#ifndef _ZKCLIENT_MULTIREG_H_
#define _ZKCLIENT_MULTIREG_H_
#include <stddef.h>
#include <signal.h>
#include <utility>
#include<map>
#include<string>
#include<vector>

#include "zookeeper/zookeeper.h"
#include "zookeeper/zookeeper_log.h"

using std::string;
using std::map;
using std::pair;
using std::vector;

struct CallbackData
{
    CallbackData(const string& d,void* p):data(d), ctx(p){}
    CallbackData(const char* d,void* p):data(d), ctx(p){}
    string data;
    void* ctx;
};

class MutexGuard
{
public:
    MutexGuard(pthread_rwlock_t * rwlock, bool type) // type = false 读锁加锁，type = true 写锁加锁 
    {
        m_rwlock = rwlock;
        if(m_rwlock == NULL)
        {
            LOG_ERROR(("MutexGuard rwlock is null"));
            exit(0);
        }
        if(type)
            pthread_rwlock_wrlock( m_rwlock );
        else
            pthread_rwlock_rdlock( m_rwlock );
    }
    ~MutexGuard()
    {
        pthread_rwlock_unlock( m_rwlock );
    }
private:
    pthread_rwlock_t * m_rwlock;

};

typedef vector<string> PathVec;
typedef vector<string>::iterator ItrPathVec;

typedef map<string, vector<string> > NodeMap;
typedef map<string, vector<string> >::iterator ItrNodeMap;

class ZkCallBackFun
{
public:
    static void findWatcherFn(zhandle_t *zh, int type, int state, const char *path,void *content);

    static void stringCompletionPathCall(int rc, const struct String_vector *strings, const void *data);               

};

class ZkClient
{
public:
    ZkClient();

    ~ZkClient();

    bool init( const string& zkCluster,int sessTimeout = 0);

    void reConnect();

    void setConnectStatus(bool status=false);
    bool getConnectStatus();

public:

    int firstWatchPathAsync(const string& path);

    int reWatchPathAsync(const string& path);

    int reWatchPathMultAsync();

    bool findPathInfo(const string& path);

    void setMapNodeInfo(const string& path,vector<string>& vec);

    string getMapNodeInfo(const string& service);

    int getRandom();

private:
    PathVec          _M_vPath;
    NodeMap          _M_mNode;
    string           _M_strZkCluster;
    int              _M_nSessTimeout;
    bool             _M_eConnState;
    zhandle_t*       _M_pZkHandle;

};

#endif