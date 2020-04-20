#include<iostream>
using namespace std;

int a=10;

char * returnstr1()
{
	static int num=0;
	char *ch="hello world";
	//return ch;
	num++;
	cout<<num<<endl;
	return ch;
}

char *returnstr2()
{
	char ch[]="hyelloaorld";
	return ch;
}

char *returnstr3()
{
	static char ch[]="aello world";
	return ch;
}

int main()
{
char *str=NULL;
str=returnstr1();
cout<<"指针指向内存内容:"<<str<<endl;
str=returnstr2();
cout<<"栈内容："<<str<<endl;
str=returnstr3();
cout<<"静态存储去内容："<<str<<endl;

str=returnstr1();
str=returnstr1();
//cout<<num<<endl;

cout<<"a=";
cout<<a<<endl;

float a=9.5;
a=a-1;
cout<<"a="<<a<<endl;

::a=::a-1;
cout<<"::a="<<::a<<endl;

return 0;
}
