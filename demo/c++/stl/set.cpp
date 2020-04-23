#include<iostream>
#include<set>
#include<cstring>

using namespace std;

 void print(set<int> s)
{
set<int>::iterator iter;
for(iter=s.begin();iter!=s.end();iter++)
{
cout<<*iter<<endl;
}

cout<<"---------"<<endl;
}

struct ltstr
{
bool operator() (const char* s1,const char* s2)const
{
return strcmp(s1,s2)<0;
}
};

int main()
{
int a[10]={1,4,1,2,3,5,2};

set<int> s(a,a+4);
print(s);

for(int i=0;i<sizeof(a)/sizeof(int);i++)
s.insert(a[i]);

print(s);

if(s.find(5)!=s.end())
	cout<<"find 5"<<endl;
s.clear();
print(s);

if(s.empty())
	cout<<"s is empty"<<endl;
const char*  b[]={"yeke","abc","ddd"};
set<const char*,ltstr >sc(b,b+3);

set<const char *,ltstr>::iterator iter;
for(iter=sc.begin();iter!=sc.end();iter++)
{
cout<<*iter<<endl;
}

return 0;
}
