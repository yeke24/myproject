#include<iostream>
using namespace std;

class memory
{
public:
	memory(int length)
	{
		_length=length;
		memo= new int [_length];
		for(int i=0;i<_length;i++)
		{
			memo[i]=0;
		}
		cout<<"分配内存成功！"<<endl;
	}

	~memory()
	{
		delete[] memo;
		//delete memo;
		if(memo!=NULL)
			memo=NULL;

		cout<<"释放内存成功！"<<endl;
	}

public:
	void output()
	{
		for(int i=0;i<_length;i++)
		{
			cout<<memo[i]<<" ";
		}
		cout<<endl;
	}	

private:
	int *memo;
	int _length;
};

int main()
{
memory mem(10);
mem.output();

return 0;
}
