#include<iostream>

using namespace std;

void arrkey(int * arr, const int &size, const int &type);

int main()
{
	int a[10]={0};

	for(int i=0; i<10; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

	int type=1;
	arrkey(a, 10, type);

	for(int i=0; i<10; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

	type =4;
	arrkey(a, 10, type);

	for(int i=0; i<10; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

	return 0;
}

void arrkey(int * arr, const int &size, const int &type)
{
	if(1==type || 2==type || 3==type)
	{
		arr[1]=1;
		arr[2]=1;
		arr[3]=1;
	}
	else if(4==type || 5==type || 6==type)
	{
		arr[4]=1;
		arr[5]=1;
		arr[6]=1;
	}
}