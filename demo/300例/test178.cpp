//#pragma comment(lib,"178.lib")

#include "178.h"
#include<iostream>
using namespace std;

int main()
{
	double res;
	res=Add(10,2.3);
	cout<<"调用动态库，两数和位："<<res<<endl;
	return 0;
}

