#include<iostream>
using namespace std;

int main()
{
int *a=new int[10];
int *b=a;
cout<<hex;

for(int i=0;i<10;i++)
{
*a=i;
cout<<a<<" "<<*a<<endl;
a++;

}
cout<<"b的地址："<<b<<endl;
cout<<"a当前指向的地址:"<<a<<endl;
delete[] a;
a=NULL;

return 0;
}
