#include<iostream>
#include<cstring>

using namespace std;

struct person
{
   int age;
   char name[10];
};

int main()
{
person p1,p2;

person *pp;

pp=&p1;

p1.age=18;
//p1.name="yeke";
strcpy(p1.name,"yeke");

cout<<"p1 age:"<<p1.age<<" p1 name:"<<p1.name<<endl;

p2.age=pp->age;
strcpy(p2.name,pp->name);

cout<<"p2 age:"<<p2.age<<" p2 name:"<<p2.name<<endl;


return 0;
}

