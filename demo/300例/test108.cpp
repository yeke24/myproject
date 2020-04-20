#include<iostream>
using namespace std;

void fun1()
{
	cout<<"fun1 run."<<endl;
}

void fun2()
{
	cout<<"fun2 run."<<endl;
}

void fun3()
{
	cout<<"fun3 run."<<endl;
}

void Function(int a)
{
   switch(a)
   {
	case 1:
		fun1();
		break;
	case 2:
		fun2();
		break;
	case 3:
		fun3();
		break;		
   }
}

int main()
{
int choice;
cout<<"this program has three function"<<endl;
bool flag=true;

while(flag)
{
   cout<<"please cin your choice"<<endl;
   cin>>choice;
	
   Function(choice);

   cout<<"if you want to keep,please cin 0,not 1"<<endl;

   int x;
   cin>>x;
   if(1==x)
   {
	flag=false;
	cout<<"quit."<<endl;
   }

}

return 0;
}
