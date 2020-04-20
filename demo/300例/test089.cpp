#include<string>
#include<iostream>

using namespace std;

void change_name(string &name,const  string later)
{
	name=later;
}

int main()
{
string cname;
string ename;

cin>>cname;
cout<<"cname:"<<cname<<endl;

cin>>ename;

change_name(cname,ename);

cout<<"change name:"<<cname<<endl;

return 0;
}
