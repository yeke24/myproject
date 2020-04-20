#include<iostream>
using namespace std;

template<class T1,class T2>
class multitype
{
private:
	T1 x;
	T2 y;

public:
	multitype(T1 t1, T2 t2);
	void show();
	void maxput();
};

template<class T1,class T2>
multitype<T1,T2>::multitype(T1 t1,T2 t2)
{
	x=t1;
	y=t2;
}

template<class T1,class T2>
void multitype<T1,T2>::show()
{
	cout<<x<<" "<<y<<endl;
}

template<class T1,class T2>
void multitype<T1,T2>::maxput()
{
	cout<<(x>y?x:y)<<endl;
}

int main()
{
multitype<int,double> m(1,2.1);
m.show();
m.maxput();

multitype<double, char> b(3.6,'y');
b.show();
b.maxput();

return 0;
}

