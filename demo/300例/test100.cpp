#include<iostream>
#include<cstring>
using namespace std;

void sequence(char **ch, int row, int col)
{
   for(int i=0;i<row-1;i++)
   {
	for(int j=i+1;j<row;j++)
	{
		if(ch[i][0]>ch[j][0])
		{
			char *ch1=new char[col];
			strcpy(ch1,ch[i]);
			strcpy(ch[i],ch[j]);
			strcpy(ch[j],ch1);
		}		
	}
   }
}

int main()
{
int m=5,n=50;

cout<<"现有5本英文图书，名字分别为:"<<endl;

char **ch=new char*[m];

for(int i=0;i<m;i++)
	ch[i]=new char [n];

strcpy(ch[0],"C++ Primer");
strcpy(ch[1],"More Effective C++");
strcpy(ch[2],"Essential C++");
strcpy(ch[3],"Imperfect C++");
strcpy(ch[4],"Head First Java");

for(int i=0;i<5;i++)
	cout<<ch[i]<<endl;

cout<<"排序后:"<<endl;
sequence(ch,m,n);
for(int i=0;i<5;i++)
	cout<<ch[i]<<endl;

delete[] ch;
ch=NULL;

return 0;
}
