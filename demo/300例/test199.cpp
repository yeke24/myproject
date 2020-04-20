#include<iostream>
#include<memory>

using namespace std;

int main()
{
double *p=new double(0.5);
auto_ptr<double> ap1(p);
auto_ptr<double> ap2=ap1;

//cout<<*ap1<<endl;
cout<<*ap2<<endl;
cout<<*ap1<<endl;

cout<<"dshh"<<endl;
cout<<"ad"<<endl;

return 0;
}
