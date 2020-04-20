#include<iostream>
using namespace std;

int main()
{
int apple_num=60;
int people=12;
int apple_per_people;

if(people!=0)
{
   apple_per_people=apple_num/people;
   cout<<"per people has apple:"<<apple_per_people<<endl;
}
else
   cout<<"people is zero."<<endl;

return 0;
}
