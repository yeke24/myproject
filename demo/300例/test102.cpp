#include<iostream>
using namespace std;

class animal_ancestor
{
public:
	animal_ancestor(){}
	~animal_ancestor(){}
	void respire()
	{
		cout<<"可以呼吸。"<<endl;
	}

private:

};

class ape:public animal_ancestor
{
public:
	ape(){}
	~ape(){}
	void move()
	{
		cout<<"可以行走。"<<endl;
	}
private:
};

class human:public ape
{
public:
	human(){}
	~human(){}
	void miss()
	{
		cout<<"可以思念。"<<endl;
	}


};

int main()
{
human h1;
cout<<"人类"<<endl;
h1.respire();
h1.move();
h1.miss();

return 0;
}

