#include<iostream>
using namespace std;

int main()
{
int src[10];
int des[10];

for(int i=0;i<10;i++)
{
	src[i]=i;
	des[i]=src[i];
}
cout<<"src:"<<endl;
for(int i=0;i<10;i++)
	cout<<src[i]<<" ";

cout<<endl<<"des:"<<endl;
for(int i=0;i<10;i++)
	cout<<des[i]<<" ";

cout<<endl;

return 0;
}

