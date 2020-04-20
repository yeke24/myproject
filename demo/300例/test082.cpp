#include<iostream>
#include<cstring>
using namespace std;

int main()
{
char ch[]="Hlellolvoe,,Wco+r+l d";

int i=0;

while(i<strlen(ch))
{
   if(i%2==0)
	cout<<ch[i];
   i++;
}

cout<<endl;

return 0;
}

