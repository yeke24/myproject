#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<assert.h>
#include <cstdlib>

using namespace std;

struct score
{
	int math;
	int physics;
	int english;
	int computer;
};

class student
{
private:
	string name;
	long num;
	int age;
	char sex;
	int count;
	score s;
	ofstream fout;
	ifstream fin;

public:
	student();
	~student();
	void mainpage();
	void readfile();
	void writefile();
	void insert();
	void display();	
};

void student::readfile()
{
cout<<"name num age sex math physics english computer"<<endl;
fin.open("stuinfo.txt",ios::in|ios::out);
if(fin.good())
{
	while(!fin.eof())
	{
		fin>>name>>num>>age>>sex>>s.math>>s.physics>>s.english>>s.computer;
		cout<<name<<" "<<num<<" "<<age<<" "<<sex<<" "<<s.math<<" "<<s.physics<<" "<<s.english<<" "<<s.computer<<endl;
	}
	//cout<<"写入成功"<<endl;
//	fin.close();
}
fin.close();
}

void student::writefile()
{
	fout.open("stuinfo.txt",ios::out|ios::in|ios::ate);
	if(fout.good())
	{
		fout<<'\n'<<name<<" "<<num<<" "<<age<<" "<<sex<<" ";
		fout<<s.math<<" "<<s.physics<<" "<<s.english<<" "<<s.computer;
	}
	cout<<"写入成功"<<endl;
	fout.close();
}

student::student()
{
name="";
num=0;
age=0;
sex=' ';
count=0;
s.math=0;
s.physics=0;
s.english=0;
s.computer=0;
}

student::~student()
{}

void student::insert()
{
	char n;
	do
	{
		cout<<"cin name:";
		cin>>name;
		cout<<"cin num:";
		cin>>num;
		cout<<"cin age:";
		cin>>age;
		cout<<"cin sex:";
		cin>>sex;
		cout<<"cin math:";
		cin>>s.math;
		cout<<"cin physics:";
		cin>>s.physics;
		cout<<"cin english:";
		cin>>s.english;
		cout<<"cin computer:";
		cin>>s.computer;
		writefile();
		count++;
		cout<<"继续cin y or Y";
		cin>>n;
	}while(n=='Y'||n=='y');
	system("cls");
	mainpage();
}

void student::display()
{
readfile();
mainpage();
}

void student::mainpage()
{
int choose;
cout<<"\n\n";
cout<<"\t\t\t 学生数据管理系统V1.0\n";
cout<<"\t     ";
for(int i=0;i<47;i++)
	cout<<"*";

cout<<"\n";
cout<<"\t          *    1.录入。\t\t\t     *\n";
cout<<"\t          *    2.读取。\t\t\t     *\n";
cout<<"\t          *    other.退出。\t\t\t     *\n";
cout<<"\t     ";
for(int i=0;i<47;i++)
	cout<<"*";
cout<<"\n\n";
cout<<"请输入你要进行的操作：";
cin>>choose;
switch(choose)
{
case 1:
	insert();
	break;
case 2:
	display();
	break;
default:
	exit(-1);

}

}

int main()
{
student stu;
stu.mainpage();

return 0;
}

