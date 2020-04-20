#include<iostream>
using namespace std;

#define ROW 20
const int COL=2;

int main()
{
int people[ROW][COL]={{0,0},{1,1},{1,2},{0,2},{0,1},{0,0},{1,0},{1,2},{1,1},{1,0},{0,2},{0,1},{0,0},{0,2},{1,2},{1,1},{1,0},{1,2},{0,2},{1,1}};

int *num=new int[6];

for(int i=0;i<6;i++)
	num[i]=0;

for(int i=0;i<ROW;i++)
{
   switch(*(*(people+i)+1))
   {
   	case 0:
		if(people[i][0]==0)
			(*num)++;
		else
			(*(num+1))++;
		break;
	case 1:
		if(people[i][0]==0)
			(*(num+2))++;
		else
			(*(num+3))++;
		break;
	case 2:
		if(people[i][0]==0)
			(*(num+4))++;
		else
			(*(num+5))++;
		break;	
	default:
		break;
   }
}
cout<<"来自ABC的男女人数依次为："<<endl;
for(int i=0;i<6;i++)
	cout<<*(num+i)<<" ";
cout<<endl;

cout<<"a的人数："<<(*num)+(*(num+1))<<endl;
cout<<"b的人数："<<(*(num+2))+(*(num+3))<<endl;
cout<<"c的人数："<<(*(num+4))+(*(num+5))<<endl;

delete[] num;
num=NULL;

return 0;
}
