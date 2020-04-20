#include<stdlib.h>
#include<iostream>

using namespace std;

int doStringToInt(string &data)
{
int idata=atoi(data.c_str());
return idata;
}

int main()
{
string a("10");

if(10==doStringToInt(a))
	cout<<"a is int 10"<<endl;

return 0;
}
