#include<iostream>
#include<list>

using namespace std;

int main()
{
list<int>l;
list<int>::iterator ite;

int num=0;
l.push_back(1);
l.push_back(2);
l.push_back(3);
l.push_back(4);
l.push_back(5);

num=l.size();
cout<<"l的个数："<<num<<endl;

for(ite=l.begin();ite!=l.end();ite++)
{
	cout<<*ite<<" ";
}
cout<<endl;

l.erase(l.begin());
l.pop_back();
l.pop_front();
l.remove(3);

for(ite=l.begin();ite!=l.end();ite++)
{
        cout<<*ite<<" ";
}
cout<<endl;

l.clear();

return 0;
}
