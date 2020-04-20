#include<iostream>
#include<string>
#include <string.h>
using namespace std;

int main()
{
string one("yeke");
cout<<one<<endl;

string two(10,'$');
cout<<two<<" "<<two.size()<<" "<<two.length()<<" "<<two.capacity()<<endl;

string three=one;
cout<<three<<endl;

one+=" is";
cout<<one<<endl;

three[0]='p';
cout<<three<<endl;

string four=two+three;
cout<<four<<endl;

string five(four,4,12);
cout<<five<<endl;

string six(&five[5],&five[12]);
cout<<six<<" "<<six.size()<<six.length()<<" "<<six.capacity()<<endl;

return 0;
}
