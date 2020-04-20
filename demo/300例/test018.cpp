#include<iostream>
using namespace std;

int main()
{
cout<<"图书馆系统功能:"<<endl;
cout<<"   1-借书功能"<<endl;
cout<<"   2-还书功能"<<endl;
cout<<"   3-图书分类管理"<<endl;
cout<<"   4-图书基本信息"<<endl;
cout<<"   5-图书状态查询功能"<<endl;
cout<<"   0-退出"<<endl;

int status;
int count=10;

while(count!=0)
{
   cout<<"请输入您的选择：";
   cin>>status;

   if(0==status)
   {
	cout<<"退出成功"<<endl;
	break;
   }
   else if(1==status)
	cout<<"进入借书功能"<<endl;
   else if(2==status)
	cout<<"进入还书功能"<<endl;
   else if(3==status)
	cout<<"进入图书分类功能"<<endl;
   else if(4==status)
	cout<<"进入图书基本信息功能"<<endl;	
   else if(5==status)
	cout<<"进入图书信息查询功能"<<endl;

   count--;
}

return 0;
}

