#include<iostream>
#include<vector>

using namespace std;

//template<class T>
class mystack
{
public:
	mystack(){};
	~mystack(){};

public:
		void push(int a);
		int top();
		void pop();
		int minmystack();

private:
	vector<int> ve;
}

void mystack::push(int a)
{
	ve.push_back(a);
}

int mystack::top()
{
	return *ve.rbegin();
}

void mystack::pop()
{
	ve.pop_back();	
}

int mystack::minmystack()
{
	int min=ve[0];

	vector<int>::iterator itr;

	for(itr=ve.begin()+1;itr!=ve.end();itr++)
	{
		if(itr*<min)
		{
			min=*itr;
		}
	}
	return min;
}

int main()
{
	mystack my;
	my.push(-1);
	my.push(3);
	my.push(-3);

	cout<<my.minmystack()<<endl;
	my.pop();
	cout<<my.top()<<endl;
	cout<<my.minmystack()<<endl;

	return 0;
}