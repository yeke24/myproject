#include<iostream>
#include<string>

using namespace std;

struct newtype
{
int a;
char ch;
string str;
};

int main()
{
newtype *new_type_point, new_type;

new_type_point=&new_type;

new_type.a=1;
new_type.ch='p';
new_type_point->str="yyyy";

cout<<sizeof(newtype)<<endl;

cout<<(*new_type_point).a<<endl;
cout<<new_type.ch<<endl;
cout<<new_type_point->ch<<endl;
cout<<&(new_type_point->str)<<endl;
cout<<(*new_type_point).str<<endl;
cout<<&new_type.str<<endl;

string * str_point;
str_point=&new_type.str;
cout<<str_point<<*str_point<<endl;

//cout<<new_type_point.str<<endl;

return 0;
}
