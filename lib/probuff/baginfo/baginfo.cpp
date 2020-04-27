#include<iostream>
#include<string>
#include <json/json.h>
#include<glog/logging.h>

#include "game.pb.h"

using namespace std;
char sConfigFile[256] = {0};

int main()
{
    
    if(2 != argc)
    {
        cout<<"main need cfgfile:"<<argv[0]<<endl;
        return 0;
    }
    snprintf(sConfigFile,sizeof(sConfigFile),"%s",argv[1]); 

    ifstream ifs_(sConfigFile);
    string line_;

    while (ifs_.good())
    {
        getline(ifs_, line_);
    }
    
    if(line_.empty())
        return 0;

    pt::bag_info_list rsp{};
    rsp.set_ret(pt::bag_info_list_RET_SUCCESS);

    Json::Reader  reader;
    Json::Value   value;

    if(reader.parse(line_,value))
    {
        Json::Value& ref =value["domain"];

        pt::obj_domain domain = rsp.mutable_obj_domain();
 
        domain->set_baseurl(ref.get("baseurl","").asString());
        domain->set_soundbase(ref.get("soundbase","").asString());

        //value["bag_info"];
        cout<<"baseurl"<<ref.get("baseurl","").asString()<<endl;
        cout<<"soundbase"<<ref.get("soundbase","").asString()<<endl;
        //Json::Value& ref =value["domain"];
    }
/*    auto user_info = rsp.mutable_user_info();
    user_info->set_nickname("dsw");
    user_info->set_icon("345DS55GF34D774S");
    user_info->set_coin(2000);
    user_info->set_location("zh");*/
/*
    for (int i = 0; i < 5; i++) {
        //auto bag_info = rsp.add_bag_info();
        pt::single_bag_info bag_info = rsp.add_bag_info();
        bag_info->set_time();
        bag_info->set_kill();
        bag_info->set_dead(i * 2);
        bag_info->set_assist(i * 5);
    }

    std::string buff{};
    rsp.SerializeToString(&buff);

    std::cout<<"####"<<std::endl;
    std::cout<<buff<<std::endl;
    std::cout<<"####"<<std::endl;

    pt::rsp_login rsp2{};
    if (!rsp2.ParseFromString(buff)) {
        std::cout << "parse error\n";
    }
    auto temp_user_info = rsp2.user_info();
    std::cout << "nickname:" << temp_user_info.nickname() << std::endl;
    std::cout << "coin:" << temp_user_info.coin() << std::endl;
    for (int m = 0; m < rsp2.record_size(); m++) {
        auto temp_record = rsp2.record(m);
        std::cout << "time:" << temp_record.time() << " kill:" << temp_record.kill() << " dead:" << temp_record.dead() << " assist:" << temp_record.assist() << std::endl;
    }*/

}
