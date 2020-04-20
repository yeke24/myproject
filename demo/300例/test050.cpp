#include<iostream>
using namespace std;

const int M=10;

int main()
{
bool flag=false;

int arr[M];

int i=0;
int j=M;

while(!flag)
{
	if(i>M-1)
	{
		j--;
		if(j==0)
			flag=true;
		
		cout<<arr[j]<<" ";
	}
	else
	{
		cin>>arr[i];
		i++;
	}

}
cout<<endl;

return 0;
}
