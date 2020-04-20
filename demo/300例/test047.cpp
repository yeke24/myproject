#include<iostream>
using namespace std;

int main()
{
int all[30];

int yijiao[15];
int jidu[15];

int i,k,yijiao_count,yijiao_index,jidu_count;

for(i=0;i<30;i++)
	all[i]=i+1;

i=0;
k=0;
yijiao_count=0;
yijiao_index=0;
jidu_count=0;

while(yijiao_count<15)
{
	if(all[i]!=0)
		k++;

	if(k==9)
	{
		yijiao[yijiao_index]=all[i];
		yijiao_index++;
		all[i]=0;
		k=0;
		yijiao_count++;
	}

	i++;
	if(i==30)
		i=0;
}

for( i=0; i<30;i++)
{
	if(all[i]!=0)
	{
		jidu[jidu_count]=all[i];
		jidu_count++;
	}

}

cout<<"yijiao:"<<endl;
for(i=0;i<15;i++)
{
	cout<<yijiao[i]<<" ";
}
cout<<endl;

cout<<"jidu:"<<endl;
for(i =0;i<15;i++)
{
	cout<<jidu[i]<<" ";
}
cout<<endl;

return 0;
}
