#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <map>
#include <string>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class config
{
public:
    static config* instance();
    config(const string& file_name);
    ~config(void);
    const string& operator[](const string &key) const;
    const string& getCfg(const string& key) const;
    string  getString(string key, string defaultval = "");
    int     getInt(string key, int defaultval = 0);
    static string strNull ;

private:
    typedef map<string, string> map_config;
    map_config m_config;
    static config* _instance;
};



#endif

