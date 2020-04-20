#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main()
{
int a=1234;
char ch[10];

//itoa(a,ch,10);
snprintf(ch, sizeof(ch), "%d", a);
cout<<"int a to char :"<<ch<<endl;

int b=0;
char *ch1="123";
b=atoi(ch1);
cout<<"字符串ch变为整数为："<<b<<endl;

return 0;
}
