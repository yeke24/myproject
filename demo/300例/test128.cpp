#include<iostream>
using namespace std;

class human
{
public:
	bool getBeauty()
	{
		return m_beauty;
	}
	
	bool m_beauty;
};

class Chinese:virtual public human
{
};

class woman:virtual public human
{
};

class me: public Chinese, public woman
{
public:
	me(bool a)
	{
		m_beauty=a;
	}
};

int main()
{
me m(true);
cout<<m.getBeauty()<<endl;

m.m_beauty=false;
cout<<m.getBeauty()<<endl;

return 0;
}
