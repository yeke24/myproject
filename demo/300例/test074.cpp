#include<iostream>
using namespace std;

int main()
{
int a=1234;
char ch[4];

for(int i=0;i<sizeof(int);i++)
	cout<<((char*)&a)[i]<<endl;

return 0;
}
