#include<iostream>
using namespace std;

int main()
{
char student[5][10];

cout<<"输入5个英文姓名，首字母大写："<<endl;

for(int i=0;i<5;i++)
	cin>>student[i];

for(int i=0;i<5;i++)
{
	for(int j=i+1;j<5;j++)
	{	int index=0;
		
		do
		{
			if(student[i][index]>student[j][index])
			{
				char temp[10];

				for(int k=0;k<10;k++)
				{
					temp[k]=student[i][k];
					student[i][k]=student[j][k];
					student[j][k]=temp[k];
				}
				index=10;
			}			

			else if(student[i][index]==student[j][index])
			{
				index++;
			}
					
			else
			{
				index=10;
			}
		}while(index<10);
	}
}

cout<<"按字母排序后:"<<endl;
for(int i=0;i<5;i++)
	cout<<student[i]<<endl;

return 0;
}
