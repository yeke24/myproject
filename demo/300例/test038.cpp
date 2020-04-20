#include<iostream>
using namespace std;

struct enter
{
int row;
int col;
};

int main()
{
int arr[4][4]={{1,1,0,1},{1,1,2,1},{1,0,0,1},{3,0,1,1}};

enter enter_box;
enter_box.row=1;
enter_box.col=2;

for(int i=enter_box.row;i<4;i++)
{
	for(int j=enter_box.col;j>=0;j--)
	{
		if(arr[i][j]==0)
		{
			enter_box.row=i;
			enter_box.col=j;
			cout<<"("<<enter_box.row<<","<<enter_box.col<<")->";
		}
		else if(arr[i][j]==3)
		{
			cout<<"到达目的地"<<endl;
		}
		else
		{}
	}
}

return 0;
}
