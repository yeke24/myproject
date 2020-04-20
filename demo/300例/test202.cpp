#include<iostream>
using namespace std;

int main()
{
int n;
cin>>n;

int laugh;
for(int i=1;i<=n;i*=2)
{
	for(int j=1;j<=i;j++)
		laugh++;
}
cout<<laugh<<endl;

return 0;
}
