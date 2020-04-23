#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void print(vector<int> &v)
{
vector<int>::iterator iter=v.begin();
for(;iter!=v.end();iter++)
	cout<<*iter<<" ";
cout<<endl;
}

int main()
{
vector<int> v;
int values[]={1,3,5,7};
v.insert(v.end(),values+1,values+3);
print(v);

cout<<v.size()<<endl;

return 0;

v.push_back(9);
print(v);

v.insert(v.begin(),1,2);
print(v);

v.erase(v.begin()+2);
print(v);

v.erase(v.begin());
print(v);

v.insert(v.begin()+1,4);
print(v);

v.insert(v.end()-1 ,4, 6);
print(v);

vector<int>::iterator iter=find(v.begin(),v.end(),3);
cout<<*iter<<"--3--"<<endl;

for(vector<int>::iterator iter=v.begin();iter!=v.end();iter++)
	if(*iter==9)
		cout<<*iter<<"--3"<<endl;

v.erase(v.begin()+1,v.begin()+3);
print(v);

v.pop_back();
print(v);

v.clear();
print(v);

if(true==v.empty())
{
cout<<"null"<<endl;
}

return 0;
}
