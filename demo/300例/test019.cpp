#include<iostream>
#include<string>
#include<stdio.h>
#include<string.h>

using namespace std;
#define code "123456"
const char *codes="1234567";

int main()
{
string putcode;
cout<<"请输入密码"<<endl;

cin>>putcode;

if(code==putcode)
	cout<<"密码正确"<<endl;
else
	cout<<"密码错误"<<endl;

char cod[20];
snprintf(cod,sizeof(cod),putcode.c_str());
if(strcmp(codes,putcode.c_str())==0)
	cout<<"true"<<endl;
else
	cout<<"false"<<endl;

return 0;
}
