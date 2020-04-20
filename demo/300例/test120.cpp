#include<iostream>
#include<math.h>
using namespace std;

class Line
{
private:
	int x1,y1,x2,y2;

public:
        Line();
	Line(int a=0,int b=0,int c=0,int d=0);
	void printPoint();
	double getDis();
};

inline Line::Line(int a,int b,int c,int d)
{
	x1=a;
	y1=b;
	x2=c;
	y2=d;
}

inline void Line::printPoint()
{
	cout<<"A:("<<x1<<","<<y1<<")"<<endl;
	cout<<"B:("<<x2<<","<<y2<<")"<<endl;
}

inline double Line::getDis()
{
	double dis;
	dis=sqrt(double(((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))));
	return dis;
}

int main()
{
   Line line(1,8,4,12);
   line.printPoint();
   cout<<"两点距离："<<line.getDis()<<endl;

return 0;
}
