#include<iostream>
#include<stdlib.h>
#include<stdio.h>
//#include<string.h>
#include<string>

using namespace std;

string doIntToString(int data)
{
char sTmpSkid[32];
snprintf(sTmpSkid,sizeof(sTmpSkid),"%d",data);
string strString=sTmpSkid;

return strString;
}

string MemUnixTime2Str(int itime)  
{  
	time_t iTimels = (time_t)itime;
	struct tm tmTimetmp = *localtime(&iTimels);  
	char cTmp[64] = {0};
	strftime(cTmp,64,"%Y%m%d",&tmTimetmp);
	string strutime = cTmp;
	return strutime;
}  

int main()
{
int a=10;

cout<<doIntToString(a)<<endl;

if(doIntToString(a)=="10")
	cout<<"string is 10"<<endl;


cout<<MemUnixTime2Str(0)<<endl;

return 0; 
}
