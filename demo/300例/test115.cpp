#include<iostream>
using namespace std;

class xingge
{
public:
	xingge(){}
	~xingge(){}
	virtual void talk()=0;
	virtual void kind_hearted()=0;
};

class child1:public xingge
{
public:
	child1(){}
	~child1(){}

	void talk()
	{cout<<"沉默寡言"<<endl;}
	
	void kind_hearted()
	{cout<<"热心肠"<<endl;}
};

class child2:public xingge
{
public:
	child2(){}
	~child2(){}
	void talk()
	{cout<<"碎碎念"<<endl;}
	
	void kind_hearted()
	{cout<<"热心肠"<<endl;}	
};

int main()
{
xingge *_xg;
child1 c1;
child2 c2;

cout<<"xingge use c1:"<<endl;
_xg=&c1;
_xg->talk();
_xg->kind_hearted();

cout<<"xingge use 2:"<<endl;
_xg=&c2;
_xg->talk();
_xg->kind_hearted();

return 0;
}
