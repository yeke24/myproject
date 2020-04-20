#include<iostream>
#include<string>

using namespace std;

int main()
{
string str1="HELLO";
string str2="World";
string str3="hello";
string str4="hello";

if(str1!=str2)
	cout<<"str1不等于st2"<<endl;

if(bool(str3.compare(str1)))
	cout<<"str1不等于str3"<<endl;

if(bool(str3.compare(str3)))
{
}
else
{
	cout<<"str3等于str4"<<endl;
}

return 0;
}
