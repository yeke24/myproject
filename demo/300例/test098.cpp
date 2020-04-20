#include<iostream>
using namespace std;

void fenlei(int *a, int *b, int len)
{
   for(int i=0;i<len;i++)
   {
	if(a[i]==0)
		b[0]++;
	else if(a[i]==1)
		b[1]++;
   }

}

int main()
{
int sex[10]={1,1,0,0,0,1,0,0,1,1};
int num[2]={0};

fenlei(sex,num,10);

cout<<"男女数量分别为："<<num[0]<<","<<num[1]<<endl;

return 0;
}

