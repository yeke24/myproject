#include<iostream>
#include<assert.h>

using namespace std;

int main()
{
int a,b;
cout<<"please cin chushu:"<<endl;
cin>>a;

cout<<"please cin beichushu:"<<endl;
cin>>b;
assert(b!=0);
cout<<"商为："<<a/b<<endl;

return 0;
}
