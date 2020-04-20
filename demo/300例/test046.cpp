#include<iostream>

using namespace std;

int main()
{
int arr[4][4];

cout<<"输入前的矩阵为:"<<endl;

for(int i=0;i<4;i++)
{
	for(int j=0;j<4;j++)
	{
		arr[i][j]=i+j*4;
		cout<<arr[i][j]<<" ";
	}
	cout<<endl;
}

for(int i=0;i<4;i++)
{
	for(int j=i+1;j<4;j++)
	{
		int temp;
		temp=arr[i][j];
		arr[i][j]=arr[j][i];
		arr[j][i]=temp;		
	}
}

for(int i=0;i<4;i++)
{
	for(int j=0;j<4;j++)
	{
		cout<<arr[i][j]<<" ";
	}
	cout<<endl;
}

return 0;
}
