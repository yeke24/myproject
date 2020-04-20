#include<iostream>
#include<string>

using namespace std;

int main()
{
string str("hello world");

string str1;

str1=str.substr(0,5);
cout<<str1<<endl;
cout<<str.substr(6,10)<<endl;

return 0;
}
