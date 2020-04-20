#include<iostream>
#include<string>

using namespace std;

class student
{
private:
	string name;
	long num;
	int age;
	char sex;
	float score;
	int count;

public:
	student();
	void new_record();
	void listnew();
};

student::student()
{
	name="";
	num=0;
	age=0;
	sex=' ';
	score=0.0;
	count=0;
}

void student::new_record()
{
cout<<"cin name:";
cin>>name;
cout<<endl<<"cin num:";
cin>>num;
cout<<endl<<"cin age:";
cin>>age;
cout<<endl<<"cin sex:";
cin>>sex;
cout<<endl<<"cin score:";
cin>>score;
count++;	
}

void student::listnew()
{
	if(count>0)
	{
		cout<<"name:"<<name<<endl;
		cout<<"num:"<<num<<endl;
		cout<<"age:"<<age<<endl;
		cout<<"sex:"<<sex<<endl;
		cout<<"score:"<<score<<endl;
	}

}

int main()
{
student stu;
char ch;
bool flag=true;

while(flag)
{
	cout<<"cin e or E ,you can update the data of student"<<endl;
	cout<<"cin L or l ,you can show the data of student"<<endl;
	cin >>ch;

	switch(ch)
	{
		case 'e':
		case 'E':
			stu.new_record();
			break;
		case 'l':
		case 'L':
			stu.listnew();
			break;
		default:
			flag=false;
			break;
	}
}

return 0;
}
