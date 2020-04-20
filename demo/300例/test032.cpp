#include<iostream>
using namespace std;

#define M 5
const int N =5;

int main()
{
int juzhen[M][N];
int row,column;

cout<<"依次输入矩阵的各个元素："<<endl;

for(int i=0;i<M;i++)
{
   for(int j=0;j<N;j++)
   {
	cin>>juzhen[i][j];
   }
}

int max=juzhen[0][0];
for(int i=0;i<M;i++)
{
   for(int j =0;j<N;j++)
   {
	if(max<juzhen[i][j])
	{
		max=juzhen[i][j];
		row=i+1;
		column=j+1;
	}
   }

}

cout<<max<<"最大元素在("<<row<<","<<column<<")"<<endl;

return 0;
}
