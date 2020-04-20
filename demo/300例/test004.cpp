#include<iostream>
using namespace std;

int main()
{
int i;
int j;
int temp;

i=5;
j=10;
cout<<"i="<<i<<" "<<"j="<<j<<endl;

temp=i;
i=j;
j=temp;

cout<<"i="<<i<<" "<<"j="<<j<<endl;
return 0;
}
