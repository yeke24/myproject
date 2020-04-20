#include<iostream>
#include<cstring>

using namespace std;

int main()
{
char str1[]="hello world";
char str2[30];

strcpy(str2,str1);

cout<<str2<<endl;

return 0;
}
