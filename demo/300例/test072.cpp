#include<iostream>
using namespace std;

int main()
{
int *a;
int *b= new int[2];

int aa=10;
a=&aa;
*b=2;

cout<<a<<" "<<*a<<endl;
cout<<b<<" "<<*b<<endl;

delete[] b;
if(b!=NULL)
	b=NULL;

return 0;
}
