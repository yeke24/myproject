#include<iostream>
using namespace std;

int main()
{
float sum=1000;

int male=4;
int female=4;

float ticket_value_male=35.0;
float ticket_value_female=ticket_value_male/2;

float remain;

remain=sum-(male*ticket_value_male+ticket_value_female*female);

cout<<"还剩"<<remain<<"元"<<endl;

int male_remain;
male_remain=(int)(remain/ticket_value_male);

cout<<"剩余"<<remain<<"元还能让"<<male_remain<<"位男性看电影"<<endl;

return 0;
}
