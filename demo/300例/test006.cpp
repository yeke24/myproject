#include<iostream>
using namespace std;

int main()
{
int Pool_volume;
int count=3;

while(count!=0)
{
   cin>>Pool_volume;
   if(Pool_volume<100)
	cout<<"游泳的水未满，请继续加水 "<<endl;
   else
	cout<<"游泳池的水已经满了，请向另一个水池加水"<<endl;

   count--;
}

return 0;
}

