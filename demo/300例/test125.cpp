#include<iostream>
using namespace std;

class Point_And_Rectangle
{
public:
	Point_And_Rectangle(int a,int b)
	{
		length=a;
		width=b;
	}

	~Point_And_Rectangle(){}

public:
	void init()
	{
		cout<<"矩阵长："<<length<<",宽为："<<width<<endl;
		cout<<"please cin x and y 的value"<<endl;
		cin>>x;
		cin>>y;
	}
/*
	bool  PointInRectangle()
	{
		if(x<0||x>length||y<0||y>width)
			return false;
		else
			return true;
	}
*/
	void output()
	{
		if(!PointInRectangle())
			cout<<"被测点在矩形外"<<endl;
		else
			cout<<"被测点在矩形内"<<endl;
	}

private:
	bool  PointInRectangle()
        {
                if(x<0||x>length||y<0||y>width)
                        return false;
                else
                        return true;
        }

private:
	double length;
	double width;
	double x;
	double y;
};

int main()
{
Point_And_Rectangle m(10,20.5);

int goon;
do
{
	m.init();
	m.output();
	cout<<"if you want to keep , please cin 1 ,not cin other;"<<endl;
	cin>>goon;
}while(goon==1);

return 0;
}
