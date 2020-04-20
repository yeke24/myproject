#include<iostream>
#include<climits>
#include<cfloat>
using namespace std;

int main()
{
int i;
short j;
long k;
float ii;
double jj;
long double kk;

cout<<"i:("<<INT_MIN<<","<<INT_MAX<<")"<<endl;
cout<<"j:("<<SHRT_MIN<<","<<SHRT_MAX<<")"<<endl;
cout<<"k:("<<LONG_MIN<<","<<LONG_MAX<<")"<<endl;
cout<<"ii:("<<FLT_MIN<<","<<FLT_MAX<<")"<<endl;
cout<<"jj:("<<DBL_MIN<<","<<DBL_MAX<<")"<<endl;
cout<<"kk:("<<LDBL_MIN<<","<<LDBL_MAX<<")"<<endl;

return 0;
}

