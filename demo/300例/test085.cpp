#include<iostream>
using namespace std;

void change(int a, int b)
{
   int temp;
   temp=a;
   a=b;
   b=temp;
}

void change(int * a,int *b)
{
   int temp;
   temp=*a;
   *a=*b;
   *b=temp;
}

int main()
{
int aa=10,bb=2;
int *point1=&aa;
int *point2=&bb;

cout<<"origin: "<<aa<<" "<<bb<<endl;
change(aa,bb);
cout<<"值传递交换结果:"<<aa <<" "<<bb<<endl;

change(point1,point2);
cout<<"地址传递交换:"<<aa<<" "<<bb<<endl;

return 0;
}
