#include<iostream>
using namespace std;

int main()
{
int num[]={0,1,2,3,4,5,6};

int *ptr;

ptr=&num[0];

cout<<ptr<<" "<<*(ptr++)<<endl;
cout<<ptr+5<<" "<<*(ptr+5)<<endl;

return 0;
}
