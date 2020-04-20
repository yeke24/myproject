#include<iostream>
using namespace std;

int main()
{
int arr[10]={1,4,3,2,7,5,8,0,6,9};

for(int i=0;i<9;i++)
{
   for(int j=i+1;j<10;j++)
   {
	if(arr[i]>arr[j])
	{
		int temp;
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
        }
   }

}

for(int i=0;i<10;i++)
{
	cout<<arr[i]<<" ";
}
cout<<endl;

return 0;
}
