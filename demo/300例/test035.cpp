#include<iostream>
using namespace std;

int main()
{
int arr[10];
cout<<"请输入数组的10个元素:"<<endl;
for(int i=0;i<10;i++)
	cin>>arr[i];

cout<<"请输入你要找的位置"<<endl;
int temp;
cin>>temp;
cout<<temp<<"位置的值:"<<arr[temp-1]<<endl;

}

