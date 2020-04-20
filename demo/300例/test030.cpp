#include<iostream>
using namespace std;

int main()
{
int migong[4][4]={{0,0,1,1},{1,0,1,1},{1,1,0,1},{1,1,0,2}};
int col,row;
int path_row[16];
int path_col[16];
for(int i=0;i<16;i++)
{
   path_row[i]=path_col[i]=0;
}

row=col=0;
int count=0;

do
{
col=0;
do
{
switch(migong[row][col])
{
	case 0:
		path_row[count]=row;
		path_col[count]=col;
		count++;
		break;
	case 1:
		break;
	case 2:
		path_row[count]=row;
		path_col[count]=col;
		count++;
		break;
}
col+=1;
}while(col<4);
row+=1;

}while(row<4);

for(int i=0;i<count;i++)
{
	cout<<"("<<path_row[i]<<","<<path_col[i]<<")->";
}
cout<<endl;
return 0;
}

