#include<iostream>
using namespace std;

template<class T> void output(T a)
{
cout<<a<<endl;
}

int main()
{
output(1);
output(1.2);

output<int>(34);
output<double>(3.1415);

output(3.1415);

return 0;
}
