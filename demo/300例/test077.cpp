#include<iostream>
#include<malloc.h>

using namespace std;

int main()
{
int n;
int m=2;

cout<<"cin n"<<endl;
cin>>n;

int **memo;

memo=(int **)malloc(sizeof(int *)*n);

for(int i=0;i<n;i++)
	memo[i]=(int *)malloc(sizeof(int)*m);

for(int i=0;i<n;i++)
{
	for(int j=0;j<m;j++)
	{
		cin>>memo[i][j];
	}

}

cout<<"通信编号------通信号"<<endl;

for(int i=0;i<n;i++)
{
	for(int j=0;j<m;j++)
		cout<<memo[i][j]<<" ";

	cout<<endl;
}

free(memo);

return 0;
}

