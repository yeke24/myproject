#include<iostream>
#include<list>
#include<queue>
using namespace std;

int main()
{
queue<int> qu;
queue<int> qu_copy;
list<int> l;
list<int>::iterator lit;

qu.push(1);
qu.push(2);
qu.push(3);
qu.push(4);

cout<<"origin queue:"<<endl;

while(qu.empty()!=true)
{
	l.push_back(qu.front());
	cout<<qu.front()<<" ";
	qu.pop();
}
cout<<endl;

cout<<"list data:"<<endl;
for(lit=l.begin();lit!=l.end();lit++)
{
	qu_copy.push(*lit);
	cout<<*lit<<" ";
}
cout<<endl;

cout<<"qu_copy data:"<<endl;

while(qu_copy.empty()!=true)
{
	cout<<qu_copy.front()<<" ";
	qu_copy.pop();
}
cout<<endl;

return 0;
}

