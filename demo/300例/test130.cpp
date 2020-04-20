#include<iostream>
using namespace std;

template<class T> T add(T a,T b)
{
	return a+b;
}

template<typename T>T sub(T a, T b)
{
	return a-b;
} 

int  main()
{
cout<<add(1,2)<<endl;
cout<<add(1.2,2.3)<<endl;

cout<<sub(2,1)<<endl;
cout<<sub(1,2)<<endl;
cout<<sub(3.6,1.0)<<endl;

return 0;
}

