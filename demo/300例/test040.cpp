#include<iostream>
using namespace std;

int main()
{
int arr[2][3][4]={1,2,3,4,5,6,7,8,9,11,12,13,14,14,14,3245,56};

cout<<"三维数组中元素为14的三维坐标:"<<endl;
for(int i=0;i<2;i++)
{
	for(int j=0;j<3;j++)
	{
		for(int k=0;k<4;k++)
		{
			if(arr[i][j][k]==14)
				cout<<"("<<i<<","<<j<<","<<k<<")"<<endl;
		}
	}

}

return 0;
}
