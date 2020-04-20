#include<iostream>
using namespace std;

double cal(int num,double quantity)
{
   switch(num)
  {
	case 0:
		return quantity*1.50;
	case 1:
		return quantity*1.70;
	case 2:
		return quantity*4.60;
	case 3:
		return quantity*0.90;
	case 4:
		return quantity*2.50;
  }

}

int main()
{
double capital;

int shu;

cin>>shu;
int *choice=new int[shu];
int *quant=new int[shu];

for(int i=0;i<shu;++i)
{
cin>>choice[i];
cin>>quant[i];
}

for(int i=0;i<shu;i++)
	capital+=cal(choice[i],quant[i]);

delete[] choice;
choice =NULL;
delete[] quant;
quant=NULL;

cout<<"总价格为:"<<capital<<endl;

return 0;
}

