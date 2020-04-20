#include<iostream>
#include<vector>

using namespace std;

int main()
{
vector<int> v;
v.reserve(10);
for(int i=0; i<7; i++)
{
v.push_back(i);
}
try {
int iVal1=v[7];

cout<<iVal1<<endl;

// not bounds checked - will not throw
int iVal2=v.at(7);
cout<<iVal2<<endl;

// bounds checked - will throw if out of range
}catch(const exception& e) 
{cout<<e.what()<<endl;}
return 0;
}
