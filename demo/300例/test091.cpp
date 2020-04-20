#include<iostream>
#include<limits.h>
using namespace std;

double mi(int key)
{
   double result=1;
   for(int i=key;i>0;i--)
	result*=key;

   return result;
}

int main()
{
int n;

cout<<"cin a number:"<<endl;
cin>>n;

cout<<INT_MAX<<endl;

if(n>INT_MAX)
	cout<<"over int_max"<<endl;
else
	cout<<mi(n)<<endl;

return 0;
}
