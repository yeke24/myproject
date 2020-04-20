#include<iostream>
#include<string>
#include<cstring>
#include <typeinfo>
using namespace std;


template<class T> void output(T a)
{
	cout<<"参数类型为："<<typeid(a).name()<<endl;
	if(strstr(typeid(a).name(),"char")!=NULL)
	{
		if(strlen(typeid(a).name())==4)
		{}
		else
			cout<<"字符串："<<a<<endl;
	}
}

int main()
{
string str="13";
output(str);

int var1=1;
output(var1);

double var2=2.3445;
output(var2);

char ch[]="1234";
output(ch);

output('d');
output("689");

return 0;
}
