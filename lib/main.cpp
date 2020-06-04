/*************************************************************************
*     > File Name: test.cpp
*     > Author: yeke
*     > Mail:yeke.com 
*     > Created Time:
*************************************************************************/

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <json/json.h>
#include<glog/logging.h>

using namespace std;

int main()
{
    string test="{\"id\":1,\"name\":\"test\"}";
    Json::Reader  reader;
    Json::Value   value;

    if(reader.parse(test,value))
    {

        if(!value["id"].isNull())
        {
            cout<<value["id"].asInt()<<endl;
            cout<<value["name"].asString()<<endl;
        }

        int score=100;
	value["score"]=score;

	if(!value.empty()){
		cout<<"id:"<<value["id"];
		cout<<"name:"<<value["name"].asString()<<endl;
		cout<<"score:"<<value["score"];
	}
	LOG(INFO)<<value;

    }

	Json::Value val(Json::arrayValue);
	val.append(value);

	Json::Value   v;
	v["id"]=3;
	v["name"]="yeke";
	v["score"]=99;

	 LOG(INFO)<<v;	
	
	val.append(v);
	
	LOG(INFO)<<val;
	
    string mystr="yeye";
    Json::Value arrv(Json::arrayValue);
    arrv.append(mystr);
    arrv.append("keke");
    Json::Value myv="yeke";
    arrv.append(myv);
    LOG(INFO)<<arrv;

	
	Json::Value va(Json::objectValue);
	Json::Value valPay(Json::objectValue);

	int i=0;
	while(i<val.size())
	{
		Json::Value& ref = val[i];	
		string  id=ref.get("name","").asString();
		LOG(INFO)<<id;
		int score=(int)ref.get("score","").asInt();
		valPay[id]=score;
		va["free"]=valPay;	
		++i;
	}
/*
	valPay["al"]=v;
	LOG(INFO)<<valPay;
    
	v["sex"]=1;
	valPay["al"]=v;
	LOG(INFO)<<valPay;

	string a="a";
	v[a]=9;
	valPay["al"]=v;
	LOG(INFO)<<valPay;


	strContent = "";
    Json::FastWriter writer;
    strContent = writer.write(val);
*/

	LOG(INFO)<<val;
return 0;
}


