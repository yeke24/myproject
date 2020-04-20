#include<iostream>
using namespace std;

int nden(const int n)
{
int sum=1;

for(int i=0;i<n;++i)
{
    sum*=n;
}

return sum;
}

int main()
{
int num;
cout<<"请输入数字:"<<endl;

cin>>num;

cout<<num<<"的"<<num<<"次方:"<<nden(num)<<endl;
return 0;
}

