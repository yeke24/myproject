#include<iostream>
using namespace std;

class A
{
private:
	int num;
public:
	A(int n)
	{num=n;}
	~A(){}
	
	void output()
	{
		cout<<"private num is :"<<num<<endl;
	}	
};

int main()
{
A a(10);
a.output();

A b=a;
b.output();

return 0;
}
