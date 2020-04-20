#include<iostream>
#include<map>
#include<string>
#include<stdio.h>
#include <fstream>
#include<stdlib.h>

using namespace std;
typedef map<string, string> map_config;
map_config m_config;
//using namespace std;

void config(const  string& file_name)
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

string getString(string key, string defval="")
{
    map_config::const_iterator iter = m_config.find(key);
    if(iter != m_config.end())
        return iter->second;
    return defval;
}

int getInt(string key, int defval=0)
{
    map_config::const_iterator iter = m_config.find(key);
    if(iter != m_config.end())
        return atoi(iter->second.c_str());
    return defval;
}

using namespace std;

int main(int argc,char* argv[])
{
    if(2 != argc)
    {
        //printf("USAGE:%s configFile dllFile\n",argv[0]);
        cout<<"main need cfgfile:"<<argv[0]<<endl;
        return 0;
    }
   
   char sConfigFile[256] = {0};
   snprintf(sConfigFile,sizeof(sConfigFile),"%s",argv[1]); 
   
   config(sConfigFile);

   cout<<getString("yeke")<<endl;
   cout<<getInt("keke")<<endl;

return 0;
}
