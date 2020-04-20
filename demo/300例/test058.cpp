#include<iostream>
#include<string>

using namespace std;

int main()
{
string str="hello;;";
char ch=';';

cout<<"元素ch位于字符串str的第"<<str.find(ch)<<"位"<<endl;

cout<<str.find_first_not_of(ch)<<endl;
cout<<str.find_first_of(ch)<<endl;
cout<<str.find_last_not_of(ch)<<endl;
cout<<str.find_last_of(ch)<<endl;
cout<<str.rfind(ch)<<endl;

return 0;
}
