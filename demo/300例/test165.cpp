#include<iostream>
using namespace std;

int main()
{
int **a =new int*[100];

for(int i=0;i<100;i++)
	a[i]=new int [100];

for(int i=0;i<100;i++)
	for(int j=0;j<100;j++)
		a[i][j]=i+j;

delete[] a;
a=NULL;

return 0;
}
