#include<iostream>
#include<cstring>

using namespace std;

int main()
{
   char str[20]="hello";
   char str1[]="world";
   char str2[5]="aaa";

   cout<<sizeof(str2)<<endl;

   strcat(str,str1);
   strcat(str2,str1);

   cout<<str<<endl;
   cout<<str2<<endl;

   cout<<sizeof(str2)/sizeof(char)<<endl;

   for(int i=0;i<sizeof(str2);i++)
	cout<<str2[i];
cout<<endl;

return 0;
}
