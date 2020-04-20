#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
int *p;

p=(int *) malloc(sizeof(int));

cout<<*p<<" "<<p<<" "<<sizeof(*p)<<endl;

*p=5;

//&p=0x13380;
cout<<*p<<" "<<p<<" "<<&p<<endl;


return 0;
}
