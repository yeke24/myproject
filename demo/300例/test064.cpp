#include<iostream>
#include<cstring>

using namespace std;

int main()
{
char str1[]="aello world";
char str2[]="bello World";

int result;

result=strcmp(str1,str2);

if(result<0)
{
	cout<<"str1小于str2"<<endl;
}
else if(result ==0)
{
	cout<<"str1=str2"<<endl;
}
else
{
	cout<<"str1大于str2"<<endl;
}

return 0;
}

