#include<iostream>
#include<stdio.h>
#include<string>
#include<cstdlib>

using namespace std;

//#define MAXLEN 1024
const int MAXLEN=1024;

int main(int argc,char ** argv)
{
if(argc!=2)
{	
	cout<<"err,cin your name run."<<endl;
	exit(0);
}

string str;
str=argv[1];

char line[MAXLEN];

int num;
cout<<"cin your score:"<<endl;
cin>>num;

snprintf(line,sizeof(line)," scores: %d",num);

//str+=line;
//cout<<str<<endl;
//cout<<line<<endl;

str+=line;
cout<<str<<endl;

return 0;
}

