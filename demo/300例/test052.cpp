#include<iostream>

using namespace std;

int main()
{
int arr[20]={1,1,1,1,0,1,0,0,0,0,1,1,1,0,0,0,1,0,1,0};

bool index[20];

int temp=0;
int female=0;
int male=0;
int random=0;

for(int i=0;i<20;i++)
	index[i]=false;

cout<<"班级20人，输入查询编号0-19。"<<endl;

while(random<20)
{
cin>>temp;

if(temp>=0&&temp<20)
{
	if(!index[temp])
	{
		if(arr[temp]==1)
		{
			male++;
			cout<<temp<<"号为男生。";
		}	
		else if(arr[temp]==0)
		{
			female++;
			cout<<temp<<"号为女生。";
		}
		else
		{}
		
		index[temp]=true;
		random++;

		cout<<endl;
		cout<<"还没读取的编号为："<<endl;
		for(int i=0;i<20;i++)
		{
			if(!index[i])
				cout<<i<<" ";
		}
		cout<<endl;
		cout<<"请继续输入编号:"<<endl;
	}
	else
	{
		cout<<"改编号已经读取过了，请重新输入"<<endl;
	}
}
else
{
	cout<<"输入越界，请重新输入"<<endl;
}

}

return 0;
}

