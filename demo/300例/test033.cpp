#include<iostream>
using namespace std;


int main()
{
int array[2][3]={1,1,3,4,1,6};

cout<<"整数数组中元素为1的二维坐标为:"<<endl;

for(int i=0;i<2;i++)
{
   for(int j=0;j<3;j++)
   {
	if(array[i][j]==1)
		cout<<"("<<i<<","<<j<<")"<<endl;
   }

}

return 0;
}
