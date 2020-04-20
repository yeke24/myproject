#include<iostream>

using namespace std;

int main()
{
bool memo[5];
memo[0]=false;
for(int i=1;i<5;i++)
{
	memo[i]=!memo[i-1];
}

cout<<"可读内存有:"<<endl;

for(int i=0;i<5;i++)
{
	if(memo[i])
		cout<<i<<" ";
}
cout<<endl;

return 0;
}

