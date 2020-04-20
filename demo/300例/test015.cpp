#include<iostream>
using namespace std;

int main()
{
float fruit_weight;
int fruit_weight_cal;

cout<<"输入水果重量:"<<endl;
cin>>fruit_weight;

if(fruit_weight-(int)fruit_weight<0.5)
	fruit_weight_cal=(int)fruit_weight;
else
	fruit_weight_cal=(int)fruit_weight+1;

cout<<"总共的重量："<<fruit_weight_cal<<endl;

return 0;
}

