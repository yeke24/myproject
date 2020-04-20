#include<iostream>
using namespace std;

int main()
{
int shu;
cout<<"请输入一个数字："<<endl;
cin>>shu;

int *arr=new int[shu];
int index=0;
int sum=0;
arr[0]=1;

for(int i=2;i<shu;++i)
{
    if(shu%i==0)
    {
	index++;
	arr[index]=i;
    }
}
for(int i=0;i<=index;i++)
{
    sum+=arr[i];
}

delete[] arr;
if(sum==shu)
	cout<<"该数字是完数"<<endl;
else
	cout<<"该数字不是完数"<<endl;
return 0;
}
