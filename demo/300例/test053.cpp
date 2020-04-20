#include<iostream>

using namespace std;

int weishu(int chushu,int shu)
{
	double result;
	result=double(shu/chushu);
	int new_chushu=chushu;
	if((result>=0)&&(result<=9))
		return new_chushu;
	else
	{
		new_chushu =chushu*10;
		weishu(new_chushu,shu);
	}
}

int main()
{
int arr[10]={1,21,3231,423,1,11,14334,15466};

int beishu[10]={1};

for(int i=0;i<10;i++)
	beishu[i]=weishu(1,arr[i]);

for(int i=0;i<9;i++)
{
	for(int j=i+1;j<10;j++)
	{
		if(beishu[i]<=beishu[j])
		{}
		else
		{
			int temp;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			temp=beishu[i];
			beishu[i]=beishu[j];
			beishu[j]=temp;
		}
	}
}

for(int i=0;i<10;i++)
	cout<<arr[i]<<" ";

cout<<endl;

return 0;
}

