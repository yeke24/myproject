#include "configger.h"
//#include <pthread.h>
#include <fstream>
#include <string>
using namespace std;

extern char sConfigFile[256];
string config::strNull = "";
//pthread_mutex_t config_mutex = PTHREAD_MUTEX_INITIALIZER;
config* config::_instance = NULL;
config* config::instance()
{
    if(NULL == _instance)
    {
  //      pthread_mutex_lock(&config_mutex);
        if(NULL == _instance)
        {
            _instance = new config(sConfigFile);
        }
  //      pthread_mutex_unlock(&config_mutex);
    }
    return _instance;
}

config::config(const  string& file_name)
{
    ifstream ifs_(file_name.c_str());
    string line_;
    string::size_type pos_;
    while (ifs_.good())
    {
        getline(ifs_, line_);
        pos_ = line_.find("=");
        if (string::npos != pos_ && "#" != line_.substr(0,1))
            m_config[line_.substr(0,pos_)] = line_.substr(pos_ + 1);
    }
}

config::~config(void)
{
    m_config.clear();
}

const string& config::operator [](const string &key) const
{
    map_config::const_iterator ite_ = m_config.find(key);
    if (ite_ != m_config.end())
        return ite_->second;
    return strNull;
}

const string& config::getCfg(const string& key) const
{
    map_config::const_iterator iter = m_config.find(key);
    if(iter != m_config.end())
        return iter->second;
    return strNull;
}

string config::getString(string key, string defval)
{
    map_config::const_iterator iter = m_config.find(key);
    if(iter != m_config.end())
        return iter->second;
    return defval;
}

int config::getInt(string key, int defval)
{
    map_config::const_iterator iter = m_config.find(key);
    if(iter != m_config.end())
        return atoi(iter->second.c_str());
    return defval;
}

