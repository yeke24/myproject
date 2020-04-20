#include<iostream>
using namespace std;

template<class T1, class T2>
class A
{
public:
	A(){}
	A(T1 x,T2 y);
	~A(){}
	void show();
	
private:
	T1 X;
	T2 Y;
};

template<class T1,class T2>
A<T1,T2>::A(T1 x,T2 y)
{
	X=x;
	Y=y;
}

template<class T1,class T2>
void A<T1,T2>::show()
{
	cout<<"X="<<X<<endl<<"Y="<<Y<<endl;
}

template<class T1,class T2>
class B:public A<T1,T2>
{
public:
	B(){}
	B(T1 x,T2 y,T1 w,T2 l);
	~B(){}
	void display();

private:
	T1 W;
	T2 L;
};

template<class T1,class T2>
B<T1,T2>::B(T1 x,T2 y,T1 w,T2 l): A<T1,T2>::A(x,y)
{
	//A(x,y);
	W=w;
	L=l;
}

template<class T1,class T2>
void B<T1,T2>::display()
{
	cout<<"W="<<W<<endl<<"L="<<L<<endl;
}

int main()
{
#if 0
B<int,double>*q=new B<int ,double>(2,3.3,1,2.1);
cout<<"B private member:"<<endl;
q->display();
cout<<"B public A ,A private member:"<<endl;
q->show();
#endif

#if 1
B<int, double> b(2,3.3,1,2.1);
cout<<"B private member:"<<endl;
b.display();
cout<<"B public A ,A private member:"<<endl;
b.show();

A<int, double>*a=&b;
//cout<<"B private member:"<<endl;
//a->display();
cout<<"B public A ,A private member:"<<endl;
a->show();

#endif

return 0;
}
