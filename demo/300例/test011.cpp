#include<iostream>
using namespace std;

bool isRuiyear(int year)
{
   if(year%400==0 || (year%4==0)&&(year%100!=0))
   {
	return true;
   }
   else
	return false;
}

int main()
{
int year;
cin>>year;
if(isRuiyear(year))
	cout<<"是瑞年"<<endl;
else
	cout<<"不是瑞年"<<endl;

return 0;
}
