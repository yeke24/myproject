#include<iostream>
#include<string>

using namespace std;

int main()
{
string str="adhdjh\0dsfsd";
cout<<str<<endl;

for(int i=0;i<sizeof(str);i++)
{
cout<<str[i];
}
cout<<endl;

return 0;
}
