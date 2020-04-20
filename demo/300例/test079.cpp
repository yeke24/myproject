#include<iostream>
using namespace std;

int main()
{
int arr[5][6];

int (*point)[6]=arr;

int *pointp[5];

for(int i=0;i<5;i++)
{
	for(int j=0;j<6;j++)
		arr[i][j]=i+j;
}

cout<<"arr[3][4]:"<<arr[3][4]<<endl;
cout<<"*(arr[3]+4):"<<*(arr[3]+4)<<endl;
cout<<"*(*(arr+3)+4)"<<*(*(arr+3)+4)<<endl;
cout<<"(*(arr+3))[4]"<<(*(arr+3))[4]<<endl;


for(int i=0;i<5;i++)
	pointp[i]=arr[i];

return 0;
}
