#include<iostream>
using namespace std;

int main()
{
int *point;
const /*volatile*/ int changliang=12;

point=(int*)&changliang;
//point=/*(int*)*/&changliang;

*point=34;

cout<<point<<" "<<*point<<endl;
cout<<&changliang<<" "<<changliang<<endl;

return 0;
}
