#include<iostream>
using namespace std;
class String
{
 public:
        String(const char* str=NULL);   //普通构造函数
        Strng(const String &other);     //拷贝构造函数
        String & operator=(const String &other);  //赋值函数
        ~String(void);                  //析构函数
 public:
        char& operator[];
        bool operator==(const String& s1,const String& s2 );
        String & operator+=(const String &str);  //本身相加，返回this
        String & operator+(const String &s1,const String &s2) //两个String相加
        friend ostream& operator<<(ostream&out,String& s);
        friend istream& operator>>(iostream&in,String& s); 
 private：
        char *m_string ;              //保存字符串
 };
String::~String(void)
{
  cout<<"destrcut"<<endl;
  if(m_string!=NULL)                   //不为空，就释放内存
 {
   delete [] m_string;
   m_string = NULL;
 }
}
 
String::String(const char* str)    //普通构造函数
{
 cout<<construct<<endl;
 if(str==NULL)        //如果str 为NULL，就存一个空字符串“”
{
  m_string=new char[1];
  *m_string ='\0';
}
  else
{
  m_string = new char[strlen(str)+1] ;   //分配空间
  strcpy(m_string,str);
}
} 
 
String::String(const String& other)   //拷贝构造函数
{
  cout<<"copy construct"<<endl;
  m_string=new char[strlen(other.m_string)+1] ; //分配空间并拷贝
  strcpy(m_string,other.m_string);
}
 
char &String::operator[](int index)
{
   return  m_string[index];
}
 
bool operator==(const String& s1,const String& s2 )
{
   if(strcmp(s1.m_string,s2.m_string)==0)
     return ture;
   return false;
}
 
String & String::operator=(const String & other)
{
cout<<"operator = funtion"<<endl ;
if(this==&other) //如果对象和other是用一个对象，直接返回本身
{
return *this;
}
delete []m_string; //先释放原来的内存
m_string = new char[strlen(other.m_string)+1];
strcpy(m_string,other.m_string);
return * this;
}
 
String & String::operator+=(const String & str)
{
 char * temp=m_string;
 m_string=new char[strlen(m_string)+strlen(str.m_string)+1];
 strcpy(m_string,temp);
 delete[]temp;
 strcat(m_string,str.m_string);
 return *this;
} 
String & String::operator+(const String & s1,const String &s2)
{
String res;
  res.m_string=new char[strlen(s1.m_string)+strlen(s2.m_string)+1];
  strcpy(res.m_string,s1.m_string);
  strcat(res.m_string,s2.m_string);
  return res;
} 
ostream& operator<<(ostream& out,String& s)
{
 for(int i=0;i<s.length();i++) 
out<<s[i]<<""; 
return out;
}
istream& operator>>(istream& in,String& s)
{ 
char p[50]; 
in.getline(p,50); 
s=p; 
return in;
}
int main()
{
String a("hello"); //调用普通构造函数
String b("world"); //调用普通构造函数
String c(a); //调用拷贝构造函数
c=b; //调用赋值函数
return 0;
}