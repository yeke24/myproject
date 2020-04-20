#include<iostream>
using namespace std;

int main()
{

int apple_number=60;
int people=7;
int apple_remain;

if(people==0)
	cout<<"people不能为0"<<endl;
else
{
	apple_remain=apple_number%people;
	cout<<"还剩苹果个数为："<<apple_remain<<endl;
}
return 0;
}

