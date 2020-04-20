#include<iostream>
using namespace std;

int main()
{
int n;

for(int i=1;i<1000;i++)
{
	int temp=0;
	for(int j=1;j<=i/2;j++)
	{
		if(i%j==0)
			temp+=j;	
	}
	
	if(i==temp)
	{
		cout<<i<<"是完美数。"<<endl;
	}
}

return 0;
}
