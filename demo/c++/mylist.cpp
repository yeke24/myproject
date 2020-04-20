#include<list>
#include<iostream>

using namespace std;

int main()
{
list<int> lis1;

int data[6]={3,5,7,9,2,4};

lis1.push_back(2);
lis1.push_back(8);

list<int>::iterator ite;

for(ite=lis1.begin();ite!=lis1.end();ite++)
{
  cout<<*ite<<endl;
}

cout<<"######"<<endl;

list<int> lis2(data,data+6);
lis2.push_front(1);

lis2.insert(++lis2.begin(),2,0);

for(ite=lis2.begin();ite!=lis2.end();ite++)
{
  cout<<*ite<<endl;
}

lis2.erase(--lis2.end());
lis2.pop_front();

cout<<"<<<<<>>>>>"<<endl;
lis2.sort();

for(ite=lis2.begin();ite!=lis2.end();ite++)
{
  cout<<*ite<<endl;
}

cout<<">>>>"<<endl;
lis2.splice(lis2.end(),lis1,lis1.begin());
lis2.clear();
for(ite=lis2.begin();ite!=lis2.end();ite++)
{
  cout<<*ite<<endl;
}

cout<<lis2.empty()<<endl;

return 0;
}
