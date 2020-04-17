#include<iostream>
#include "snowflake.h"

using namespace std;
#include <unistd.h>

int main(int argc,char* argv[])
{
    if(2 != argc)
        cout<<"please cin workeid!"<<endl;;

    int workeid =atoi(argv[1].c_str());
    snowflake::instance()->set_workid(workeid);

    for(int i=0;i<10;++i)
    {
        int numid;
        numid= snowflake::instance()->get_unique_id();

        cout<<"第"<<i<<"次生成id:"<<numid;
        
        usleep(500);
    }

return 0;
}
