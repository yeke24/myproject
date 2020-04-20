#include<iostream>
using namespace std;

int main()
{
int count=1;

for(;count<10;)
{

int a;
a=++count;

if(a%2==0)
	cout<<"亮"<<endl;
else
	cout<<"灭"<<endl;

}

return 0;
}
