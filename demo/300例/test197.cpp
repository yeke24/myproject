#include<iostream>
#include<cstdlib>
using namespace std;

double ddiv(double a, double b)
{
	if(b==0)
		throw -1;
	return a/b;
}

int main()
{
try
{
	cout<<"2/3="<<ddiv(2,3)<<endl;
	cout<<"2/0=";
	cout<<ddiv(2,0)<<endl;
}
catch(...)
{
	cout<<"err 被除数为0."<<endl;
	exit(-1);
}

return 0;
}
