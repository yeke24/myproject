//#include "configger.h"
#include<iostream>
#include<stdio.h>
#include "configger.cpp"
#include "consume_watch.cpp"

using namespace std;
char sConfigFile[256] = {0};

int main(int argc,char* argv[])
{
   stopwatch watch;
    if(2 != argc)
    {
        cout<<"main need cfgfile:"<<argv[0]<<endl;
        return 0;
    }
   snprintf(sConfigFile,sizeof(sConfigFile),"%s",argv[1]); 
   
   //config::config(sConfigFile);
   //config cfg(sConfigFile); 
   //config::instance();
   config cfg(sConfigFile);

   cout<<cfg.getString("yek")<<endl;
   cout<<config::instance()->getInt("keke")<<endl;

   cout<<"usetimes:"<<watch.getUStime()<<"us"<<endl;

return 0;
}

