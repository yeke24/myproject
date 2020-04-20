#include<iostream>
using namespace std;

class salary
{
public:
	salary(){}
	~salary(){}
	virtual void pay(){}
private:
	
};

class member1:public salary
{
public:
	member1(double a){_total=a;}
	~member1(){}
	void pay()
	{
		cout<<"每个给员工1的薪资:"<<_total<<"元"<<endl;
	}
private:
	double _total;
};

class member2:public salary
{
public:
	member2(double a):_total(a){}
	~member2(){}
	void pay()
	{
		cout<<"每个给员工2发的薪资:"<<_total<<"元"<<endl;
	}

private:
	double _total;
};

int main()
{
member1 m1(4000.0);
member2 m2(10000.0);

salary *sa1=&m1;
salary *sa2;
sa2=&m2;

sa1->pay();
sa2->pay();

return 0;
}
