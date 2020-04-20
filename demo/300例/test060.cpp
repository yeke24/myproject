#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

int main()
{
string str="hello";

//char str1[10];
const char *ch;

ch=str.c_str();

cout<<ch<<endl;

char skey[256];
snprintf(skey,sizeof(skey),str.c_str());
cout<<skey<<endl;

ch="world";
str=ch;
cout<<str<<endl;

return 0;
}

