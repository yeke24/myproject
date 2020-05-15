#include<iostream>
#include<string.h>
using namespace std;

class mystring
{
	public:
		mystring();
		mystring(const char * str);
		~mystring();
		mystring(mystring &mys);
		mystring & operator = (const mystring & ss);			

	public:
		void getstring();
		void setstring(char * str);
		bool operator == (mystring & ss);
		void mystring::Reverse();

	private:
		char *m_data;
};

mystring::mystring()
{
	m_data = new char[1];
	m_data ='\0';
}

mystring::mystring(const char * str)
{
	int len=strlen(str);
	m_data =new char[len+1];

	strcpy(m_data, str);
}

mystring::~mystring()
{
	if(m_data!=NULL)
	{
		delete [] m_data;
		m_data =NULL;		
	}
}

mystring::mystring(mystring & mys)
{
	int len=strlen(mys.m_data);

	m_data=new char[len+1];

	strcpy(m_data,mys.m_data);
}

mystring & mystring::operator = (const mystring & ss)
{
	if(this == &ss)
		return *this;

	if(m_data!=NULL)
		delete [] m_data;

	m_data=new char[strlen(ss.m_data)+1];

	strcpy(m_data,ss.m_data);
	return *this;
}

bool mystring::operator==(mystring & ss)
{
	if(this->m_data == ss.m_data)
		return true;
	return false;
}

void mystring::setstring(char * str)
{
	if(m_data!=NULL)
		delete [] m_data; 
	m_data=new char[strlen(str)+1];
	strcpy(m_data,str);
}

void mystring::getstring()
{
	cout<<m_data<<endl;
}

void mystring::Reverse()
{
	int length = strlen(this->m_data);
	char *c_str = this->m_data;
	char temp_data;
	for (int i = 0; i < length/2; i++)
	{
		temp_data = c_str[i];
		c_str[i] = c_str[length-1-i];
		c_str[length-1-i] = temp_data;
	}
}

int main()
{
	mystring my;
	my.getstring();

	my.setstring("yeke");
	my.getstring();

	mystring ms(my);
	ms.getstring();

	return 0;
}
