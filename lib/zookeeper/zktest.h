#ifndef _ZKCLIENT_MULTIREG_H_
#define _ZKCLIENT_MULTIREG_H_

#include <stddef.h>
#include <string>
#include "zookeeper.h"
#include <signal.h>
#include <utility>
#include<vector>
#include<map>

using std::string;
using std::vector;
using std::map;

struct CallbackData
{
    CallbackData(const string& d,void* p):data(d), ctx(p){}
    CallbackData(const char* d,void* p):data(d), ctx(p){}
    string data;
    void* ctx;
};

enum ConnectionState{ZKC_CLOSED_STATE = 0, ZKC_CONNECTED_STATE , ZKC_EXPIRED_STATE};

class NodeInfo
{
public:
    NodeInfo(){};
    NodeInfo(const string& p, const string& v):_M_strPath(p),_M_strValue(v){};

    bool operator == (const NodeInfo& ni)
    {
        return ( ni._M_strPath == this->_M_strPath );
    }
    bool operator != (const NodeInfo& ni)
    {
        return !this->operator==(ni);
    }

public:
    string            _M_strPath;
    string            _M_strValue;
};

vector<NodeInfo> Node_Vec;
vector<NodeInfo>::const_iterator c_itr;

/*map<string, string> _M_NodeKey;
map<string, string>::const_iterator M_ITR;
*/

class ZkClient
{
public:
    ZkClient();

    ~ZkClient();

    void init( const string& zkCluster,int sessTimeout = 0);

    void reConnect();

    void setConnectStatus(enum  ConnectionState status);

    enum ConnectionState getConnectStatus();

    typedef vector<NodeInfo>::size_type node_size_type;
public:
    int regPathNode(const string& path, const string& value = "");

    int creatPathNodeAsync(const string& path, const string& value);

    int watchPathNodeAsync(const char* path);

    node_size_type findNodeInfo(const string& path);

    NodeInfo& getNodeInfo(node_size_type idx);

    int reRegPathNodeVec();

public:
    static const node_size_type nopos = -1;
private:
    vector<NodeInfo> _M_regNodeVec;
    string           _M_strZkCluster;
    int              _M_nSessTimeout;
    ConnectionState  _M_eConnState;
    zhandle_t*       _M_ptrZkHandle;

};

#endif