#include<iostream>
using namespace std;

class Apple
{
private:
	static int apples;
	int apple;

public:
	Apple(){apple=5;}
	~Apple(){};

	void setApples(int a,int b)
	{
		apple=a;
		apples=b;
	}

	static int getApples()
	{
		return apples;	
	}

	int getApple()
	{
		return apple;
	}
};

int Apple::apples=10;

int main()
{
cout<<"1  :"<<Apple::getApples()<<endl;
Apple a,b;

cout<<"a.apples="<<a.getApples()<<endl;
cout<<"a.apple="<<a.getApple()<<endl;
cout<<"b.apples="<<b.getApples()<<endl;
cout<<"b.apple="<<b.getApple()<<endl;

a.setApples(23,50);

cout<<"change"<<endl;
cout<<"a.apples="<<a.getApples()<<endl;
cout<<"a.apple="<<a.getApple()<<endl;
cout<<"b.apples="<<b.getApples()<<endl;
cout<<"b.apple="<<b.getApple()<<endl;

return 0;
}
