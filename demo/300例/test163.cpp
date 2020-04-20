#include<iostream>
using namespace std;

void fun1()
{
	int a=10;
	int b=20;
	int *temp=&a;
	int *p=temp;
	p=&b;
	*p=5;
	cout<<a<<" "<<b<<" "<<*temp<<" "<<*p<<endl;
}

void fun2()
{
	int a=10;
	int b=20;
	int *temp=&a;
	int *&p=temp;
	p=&b;
	*p=5;
	cout<<a<<" "<<b<<" "<<*temp<<" "<<*p<<endl;
}

int main()
{
fun1();
fun2();

return 0;
}
