#include<iostream>
#include<string>
#include<map>
#include<set>
#include<stdio.h>

using namespace std;

map<int,string>::iterator it1;
map<int, set<string> >::iterator it2; 
map<int, set<string> >m_set;

struct mydate{
   int k;
   char str[20];
   //mydate():k(0),str[20]("\0"){};
};

int main()
{
map<int,string>m_bag;

m_bag.insert( pair<int,string>(1,"yeke") );
m_bag.insert( pair<int, string> (2,"kk") );

it1=m_bag.find(1);
if(it1 !=m_bag.end())
{
cout<<"1:"<< (it1->second) <<endl;

it1->second+=",";
it1->second +="hello!";

cout<<"1:"<<it1->second<<endl;
}

int k=1;
string str("kk");

struct mydate da[4] = { {1,"kk"},{2,"ye"},{1,"yy"},{1,"yeke"} };
for(int i=0;i<4;i++)
{
cout<<da[i].k<<" "<<da[i].str<<endl;

it2=m_set.find(da[i].k);

if(it2 != m_set.end())
{
it2->second.insert(da[i].str);
}
else
{
  set<string> s;
  s.insert(da[i].str);

  m_set.insert( pair<int, set<string> > (da[i].k,s) );
}


for(it2=m_set.begin();it2!=m_set.end();it2++)
{
   int key=it2->first;

   string slist;
   set<string> ss=it2->second;
   set<string>::iterator it;
   for(it=ss.begin();it!=ss.end();it++)
   {
      if(!slist.empty())
    		  slist+=",";
    	slist+=*it;
   }
   cout<<"key:"<<key<<" str:"<<slist<<endl; 

}

}
return 0;
}
