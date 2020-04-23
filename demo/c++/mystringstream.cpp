#include<iostream>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

int main()
{
stringstream ss;

int uid=501;
string str="yeke";
char key[10]="adsfd";

ss<<str;
ss<<"_"<<uid;
ss<<"_"<<key;

cout<<ss.str()<<endl;
cout<<ss<<endl;

ss.str("");
cout<<ss.str()<<endl;

for(int i=1;i<101;i++)
{
ss<<i;
ss<<",";
}
cout<<ss.str()<<endl;

string st;
ss>>st;
cout<<st<<endl;

return 0;
}
