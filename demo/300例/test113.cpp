#include<iostream>
using namespace std;

#if 0
int add(int a,int b)
{
	return a+b;
}
#endif
#if 1
int add(int a,int b, int c=10)
{
	return a+b+c;
}
#endif
double add(double a,double b)
{
	return a+b;
}

int main()
{
cout<<"2+3="<<add(2,3)<<endl;
cout<<"2+3+4="<<add(2,3,4)<<endl;
cout<<"2.2+3.3="<<add(2.2,3.3)<<endl;

return 0;
}
