#include<iostream>
#include<cstring>

using namespace std;

int main()
{
   char ch[]="ajfdklsafj";
   cout<<ch<<endl;

   char *ptr=ch;
   ptr+=strlen(ch)/2;

   for(int i=strlen(ch)/2;i<strlen(ch);i++)
	ch[i]=ch[i+1];

   cout<<ch<<endl;

return 0;
}
