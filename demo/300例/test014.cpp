#include<iostream>
using namespace std;

int level(char ch)
{
   switch(ch)
   {
	case '!':
		return 2;
		break;
	case '*':
		return 3;
		break;
	case '/':
		return 3;
		break;
	case '%':
		return 3;
		break;
	case '+':
		return 4;
		break;
	case '-':
		return 4;
		break;
	case '=':
		return 5;
		break;
	default:
		return -1;
		break;
   }
}

int main()
{
char symbol[3];
int value[3];

cin>>symbol[0]>>symbol[1]>>symbol[2];

value[0]=level(symbol[0]);
value[1]=level(symbol[1]);
value[2]=level(symbol[2]);

if(value[0]==-1 || value[1]==-1 ||value[2]==-1)
	cout<<"库中没有输入的运算符"<<endl;
else
{
for(int i=0;i<3;i++)
   for(int j=i;j<3;j++)
   {
	if(value[i]>value[j])
	{
		char temp;
		temp=symbol[i];
		symbol[i]=symbol[j];
		symbol[j]=temp;
	}
   }
cout<<symbol[0]<<" "<<symbol[1]<<" "<<symbol[2]<<endl;

}

//cout<<symbol[0]<<" "<<symbol[1]<<" "<<symbol[2]<<endl;

return 0;
}
