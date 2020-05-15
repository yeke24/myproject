#include<iostream>
#include<string>
#include "zkclient_find.h"

using namespace std;

int main(int argc, char ** argv)
{
        string value("test");
        if(argc>1)
        {
                value=argv[1];
        }

        string host="192.168.10.99:2181,192.168.10.100:2181";
        string path ="/yeke/test";
        int timeout=10000;

        ZkClient zk_c;

        if(!zk_c.init(host, timeout))
                return 0;
        zk_c.firstWatchPathAsync(path);

        for(int i=0; i<10; i++)
        {
                cout<<zk_c.getMapNodeInfo(value)<<endl;
                sleep(100);
        }
        sleep(1000);

        return 0;
}
