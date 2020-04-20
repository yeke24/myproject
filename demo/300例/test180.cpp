#include<iostream>
using namespace std;

template<class T>
class ptr
{
private:
	T *ip;

public:
	ptr(T *p);
	~ptr();
};

template<class T>
ptr<T>::ptr(T *p)
{
	ip=p;
	cout<<"调用指针管理类构造函数。"<<endl;
}

template<class T>
ptr<T>::~ptr()
{
	ip=NULL;
	cout<<"指针管理类析构函数被调用。"<<endl;
}

int main()
{
int a=10;

ptr<int>p(&a);

return 0;
}
