#include<iostream>
using namespace std;

//const double pi=3.141592653;
#define pi 3.141592653

class circle
{
public:
	double area(double x)
	{
		return pi*x*x;
	}

	double circumfer(double y)
	{
		return 2*pi*y;
	}
public:
	double radius;
};

class newcircle
{
public:
	newcircle(double x):rad(x){}
	~newcircle(){}

	newcircle(const  newcircle & cir)
	{
		rad=cir.rad;
	}

	void operator=(newcircle &cir)
	{
		if(this==&cir)
			return ;

		rad=cir.rad;
		return ;
	}

	double area()
	{
		return pi*rad*rad;
	}

	double circumfer()
	{
		return 2*pi*rad;
	}

private:
	double rad;
};

int main()
{
//cout<<pi;

circle cir;
cout<<"请输入圆的半径:"<<endl;

cin>>cir.radius;

cout<<"圆的面积:"<<cir.area(cir.radius)<<endl;
cout<<"圆的周长:"<<cir.circumfer(cir.radius)<<endl;

//double ra;
//cout<<"请输入新圆的半径:"<<endl;
//cin>>ra;
//
newcircle c(2);
newcircle ci=c;
cout<<"new圆的面积:"<<ci.area()<<endl;
cout<<"new圆的周长:"<<ci.circumfer()<<endl;

return  0;
}
