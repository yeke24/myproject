#include<iostream>
using namespace std;

void inv(int *a, int length)
{
   int temp;
   int i,j;

   for(i=0;i<=(length-1)/2;i++)
   {
	int temp;
	j=length-i-1;
        temp= a[i];
	a[i]=a[j];
	a[j]=temp;
   }
}

int main()
{
int memo[10]={3,4,5,6,7,8,9,9};

cout<<"origin data:"<<endl;
for(int i=0;i<10;i++)
	cout<<memo[i]<<" ";
cout<<endl;

inv(memo,10);

cout<<"inv data:"<<endl;
for(int i=0;i<10;i++)
	cout<<memo[i]<<" ";
cout<<endl;

return 0;
}

