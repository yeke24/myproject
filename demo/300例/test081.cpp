#include<iostream>
using namespace std;

union test
{
int aa;
char ch;
};

int main()
{
test t1;

t1.aa=0x00000001;

cout<<"本机内存数据排列顺序为:"<<endl;

if(t1.ch==1)
	cout<<"先低后高"<<endl;
else if(t1.ch==0)
	cout<<"先搞后低"<<endl;

return 0;
}
