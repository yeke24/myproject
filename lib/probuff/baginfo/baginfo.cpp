#include<iostream>
using namespace std;

#include<fstream>
#include<string>
#include "json/json.h"
//#include<glog/logging.h>

#include "baginfo.pb.h"

using namespace std;
char sConfigFile[256] = {0};

int main(int argc,char* argv[])
{
    
    if(3 != argc)
    {
        cout<<"main need cinfile and outfile :"<<argv[0]<<endl;
        return 0;
    }
    snprintf(sConfigFile,sizeof(sConfigFile),"%s",argv[1]); 

   // string str=sConfigFile;

    ifstream ifs_(sConfigFile);
    string line_;

    while (ifs_.good())
    {
        getline(ifs_, line_);
    }
    
    if(line_.empty())
        return 0;

    mypt::bag_info_list rsp{};
    rsp.set_ret(mypt::bag_info_list_RET_SUCCESS);

    Json::Reader  reader;
    Json::Value   value;

    if(reader.parse(line_,value))
    {
        Json::Value& ref =value["domain"];

        //auto domain = rsp.mutable_domain();
	mypt::obj_domain *domain = rsp.mutable_domain();

        domain->set_baseurl(ref.get("baseurl","").asString());
        domain->set_soundbase(ref.get("soundbase","").asString());

	//cout<<"baseurl"<<ref.get("baseurl","").asString()<<endl;
        //cout<<"soundbase"<<ref.get("soundbase","").asString()<<endl;
	
	Json::Value& vlist =value["bag_info"];

	//cout<<"size:"<<vlist.size()<<endl;
	for(size_t i=0;i<vlist.size();i++)
	{
	    auto bag_info = rsp.add_bag_info();
	    Json::Value& baginfo =vlist[i];

	    //baginfo.get("bagid",0).asInt()
            //baginfo.get("name","").asString()

            bag_info->set_bagid(baginfo.get("bagid",0).asInt());
            bag_info->set_name(baginfo.get("name","").asString());
            bag_info->set_image(baginfo.get("image","").asString());
            bag_info->set_sceneurl(baginfo.get("sceneurl","").asString());
            bag_info->set_url1(baginfo.get("url1","").asString());
            bag_info->set_opertime(baginfo.get("opertime","").asString());
            bag_info->set_mtime(baginfo.get("mtime","").asString());
            bag_info->set_uptime(baginfo.get("uptime","").asString());
            bag_info->set_image800(baginfo.get("image800","").asString());
            bag_info->set_nameimg(baginfo.get("nameimg","").asString());
            bag_info->set_subtype(baginfo.get("subtype",0).asInt());
            bag_info->set_scenetime(baginfo.get("scenetime","").asString());
            bag_info->set_forcetime(baginfo.get("forcetime","").asString());
            bag_info->set_source_type(baginfo.get("source_type","").asString());
            bag_info->set_subtitle(baginfo.get("subtitle","").asString());
            bag_info->set_buy(baginfo.get("buy",0).asInt());
            bag_info->set_vip(baginfo.get("vip",0).asInt());
            bag_info->set_ejlogo(baginfo.get("ejlogo","").asString());
            bag_info->set_cnum(baginfo.get("cnum",0).asInt());
            bag_info->set_beginversion(baginfo.get("beginversion",0).asInt());
            bag_info->set_endversion(baginfo.get("Fendversion",0).asInt());
            bag_info->set_oriprice(baginfo.get("oriprice",0).asInt());
            bag_info->set_price(baginfo.get("price",0).asInt());
            bag_info->set_coin(baginfo.get("coin",0).asInt());
            bag_info->set_vipprice(baginfo.get("vipprice",0).asInt());
            bag_info->set_bt(baginfo.get("bt",0).asInt());
            bag_info->set_ptype(baginfo.get("ptype",0).asInt());
            bag_info->set_purl(baginfo.get("purl","").asString());
            bag_info->set_vurl(baginfo.get("vurl","").asString());		

	}

   }

    string buffer;
    string outf=argv[2];
	
    fstream output(outf,ios::out|ios::binary);
    rsp.SerializeToString(&buffer); //用这个方法，通常不用SerializeToOstream
    output.write(buffer.c_str(),buffer.size());

    return 0;
}
