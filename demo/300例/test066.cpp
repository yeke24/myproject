#include<iostream>
#include<string>

using namespace std;

int main()
{
string str="hello world";
string str2("c++");

cout<<str.size()<<endl;
str.replace(3,5,str2);

cout<<str<<endl;
cout<<str.size()<<endl;

return 0;
}
