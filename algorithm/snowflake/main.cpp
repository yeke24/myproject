#include<iostream>
#include <unistd.h>
#include<sys/time.h>
#include<stdio.h>
#include<string>
#include <stdlib.h>
#include<cstring>
#include "snowflake.h"

using namespace std;

struct stSignDate
{
    int     year;
    int     month;
    int     day;
    int     week;
    int     weeks;  // 一年的第几周
    time_t  ts;
    string  format;
};

void formatSignDate(time_t rawtime, stSignDate& signDate)
{
    struct tm * timeinfo;
    char timebuf[80];

    timeinfo = localtime(&rawtime);

    signDate.ts = rawtime;

    memset(timebuf, 0, sizeof(timebuf));

    if (strftime(timebuf, sizeof(timebuf), "%W", timeinfo) != 0) {
        signDate.weeks = atoi(timebuf);
    }


    memset(timebuf, 0, sizeof(timebuf));

    if (strftime(timebuf, sizeof(timebuf), "%u", timeinfo) != 0) {
        signDate.week = atoi(timebuf);
    }

    signDate.year = timeinfo->tm_year + 1900;
    signDate.month = timeinfo->tm_mon + 1;
    signDate.day = timeinfo->tm_mday;

    char buf[12];
    snprintf(buf, sizeof(buf),"%04d%02d%02d%02d%02d%02d", signDate.year, signDate.month, signDate.day, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    signDate.format = buf;
}

int main(int argc,char* argv[])
{
    if(2 != argc)
        cout<<"please cin workeid!"<<endl;;

    int workeid =atoi(argv[1]);
    snowflake::instance()->set_workid(workeid);

    for(int i=0;i<10;++i)
    {
        long int numid;
        numid= snowflake::instance()->get_unique_id();

        cout<<"第"<<i<<"次生成id:"<<numid<<endl;
        
        usleep(500);
    }

    //订单号生成 32位
    char billstr[32];
 
    //日期 12位
    stSignDate signDate;
    formatSignDate(signDate);

    //id 20位
    long int id= snowflake::instance()->get_unique_id();   

    snprintf(billstr,sizeof(billstr),"%s%ld",signDate.format,id);

    cout<<"billid:"<<billstr<<endl;
    cout<<"billid lenth:"<<sizeof(billstr)<<endl;

return 0;
}
