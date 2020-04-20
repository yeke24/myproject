#include<iostream>
using namespace std;

int main()
{
int num;
while(1)
{
cout<<"请输入一个1-50的数字:"<<endl;

cin>>num;

if(num>0&&num<=50)
{
cout<<"符合条件"<<endl;
break;
}

}

return 0;
}
