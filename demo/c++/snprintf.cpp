#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>

using namespace std;

int main()
{
char skey[20];

snprintf(skey,sizeof(skey),"%sye ke%d","aaaa",1234);

cout<<skey<<endl;

string aa=skey;
if(!aa.empty())
   {
	cout<<"aa not null"<<endl;
	cout<<aa.size()<<endl;
	cout<<aa.length()<<endl;
	aa.resize(15);
        cout<<aa.size()<<endl;
        cout<<aa.length()<<endl;
	cout<<aa<<endl;
	cout<<aa.max_size()<<endl;
   }

if(aa.find("yeke")!=string::npos)
   cout<<"has yeke"<<endl;

memset(skey, 0, sizeof(skey));
//skey[20]='\0';

int i=snprintf(skey,9,"%011d",12345);
cout<<i<<"  "<<skey<<endl;

return 0;
}

