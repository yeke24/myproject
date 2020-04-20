#include<iostream>
using namespace std;

void cal_num(double *a, int *b, int number)
{
   for(int i=0; i<number; i++)
   {
	if(a[i]<60)
		b[0]++;
	else if(a[i]<70)
		b[1]++;
	else if(a[i]<80)
		b[2]++;
	else if(a[i]<90)
		b[3]++;
	else if(a[i]<=100)
		b[4]++;
   }
}

int main()
{
double math_score[10];
int num[5]={0};
cout<<"请输入10学生的成绩:"<<endl;
for(int i=0;i<10;i++)
	cin>>math_score[i];

cal_num(math_score,num,10);

cout<<"0-60:"<<num[0]<<endl;
cout<<"60-70:"<<num[1]<<endl;
cout<<"70-80:"<<num[2]<<endl;
cout<<"80-90:"<<num[3]<<endl;
cout<<"90-100:"<<num[4]<<endl;

return 0;
}

