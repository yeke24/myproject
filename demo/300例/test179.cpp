#include<iostream>
using namespace std;

int main()
{
char ch[20]="hello world";
char *point;
point=ch;

int *aa;

cout<<sizeof(aa)<<endl;
cout<<sizeof(point)<<endl;
cout<<sizeof(ch)<<endl;

return  0;
}
