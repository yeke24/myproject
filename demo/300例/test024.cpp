#include<iostream>
using namespace std;

int main()
{
bool switcher=false;
bool switcher_ex=false;
char ch;

while(1)
{
cout<<"cin y, n, q"<<endl;

cin >>ch;

if(ch=='y')
{
switcher_ex=switcher;
switcher=true;

if(switcher_ex)
	cout<<"继续响应"<<endl;
else
	cout<<"开始响应"<<endl;
}
else if(ch=='n')
{
switcher_ex=switcher;
switcher=false;

if(switcher_ex)
	cout<<"暂停响应"<<endl;
else
	cout<<"继续等待响应"<<endl;

}
else if(ch=='q')
{
cout<<"退出成功"<<endl;
break;
}
else
	cout<<"输入不合法"<<endl;

}

return 0;
}

