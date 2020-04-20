#include<iostream>
using namespace std;

struct data
{
	int a;
	char b;
};

template<class T> T mymax(T t1,T t2)
{
   	//return t1<t2?t2:t1;
	if(t1>=t2)
		return t1;
	else
		return t2;
}

const struct data mymax(const struct data t1,const struct data t2)
{
	if(t1.a<t2.a)
		return t2;
	else if(t1.a==t2.a)
	{
		if(t1.b<t2.b)
			return t2;
		else
			return t1;
	}
	else
		return t1;
}

int main()
{
data d1,d2;
d1.a=2;
d2.a=3;
d1.b='r';
d2.b='h';

cout<<mymax(d1.a,d2.a)<<endl;
cout<<mymax(d1.b,d2.b)<<endl;
cout<<mymax(d1,d2).a<<" "<<mymax(d1,d2).b<<endl;

return 0;
}
