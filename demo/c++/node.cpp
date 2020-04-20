#include<iostream>
#include<list>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

struct Node
{
int item;
Node * p_next;
};

Node * find(Node * head,const int & val)
{
Node * start;
for(start=head; start!=0; start=start->p_next)
	if(start->item==val)
		return start;
return 0;
}

void output(const int &a)
{
cout<<a<<" ";
}

int main()
{
int a[2]={1,2};

//vector<int> b(a,a+2);
vector<int> b(10);
copy(a,a+2,b.begin()+2);
for(vector<int>::iterator ite=b.begin();ite!=b.end();++ite)
	cout<<*ite<<endl;
//cout<<b[1]<<endl;
for_each(b.begin(),b.end(),output);
cout<<endl;

return 0;
}
