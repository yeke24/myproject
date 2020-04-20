#include<iostream>
#include<cstdlib>
#include <iomanip>

using namespace std;

double ddiv(double a,double b)
{
	if(b==0)
		throw -1;
	return a/b;
}

void term_func()
{
	cout<<"函数term_func()异常被terminate()调用。\n";
	exit(-1);
}

int  main()
{
	set_terminate(term_func);
	ddiv(10,0);

	return 0;
}

