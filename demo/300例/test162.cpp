#include<iostream>
using namespace std;

class data
{
private:
	int _var;
	int *temp_point;
	bool heap_deleted;

public:
	data(){}
	data(int var);
	~data();
	void change(int x);
	void output();
};

data::data(int var)
{
	heap_deleted=false;
	temp_point=new int;
	*temp_point=var;
	_var=*temp_point;
	cout<<"构造对象"<<endl;
}

data::~data()
{
	if(heap_deleted)
	{
		cout<<"堆内存已被释放"<<endl;
	}
	else
	{
		cout<<"地址为："<<temp_point<<endl;
  		delete temp_point;
		heap_deleted=true;
		cout<<"释放堆内存"<<endl;
	}
	cout<<"对象被销毁"<<endl;
}

void data::change(int x)
{
	_var=x;
}

void data::output()
{
	cout<<"内存值为："<<_var<<endl;
}

int main()
{
data a(1);
a.~data();
a.output();

a.change(2);
a.output();

return 0;
}
