#include<iostream>
#include<string>
using namespace std;

int main()
{
cout<<"cin string:"<<endl;
string str("s 00 00 0 sysd");
//cin>>str;

cout<<"0 num:";
int count=0;
int count_space=0;
for(int i=0;i<str.length();++i)
{
   if(str[i]=='0')
   {
	count++;
   }
   else if(str[i]==' ')
   {
	count_space++;
   }
}
cout<<count<<endl;

cout<<"null num:"<<count_space<<endl;
return 0;
}
