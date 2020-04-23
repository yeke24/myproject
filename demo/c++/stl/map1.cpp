#include<map>
#include<iostream>
#include<string>

using namespace std;

void print(map<int,string> &maps)
{
map<int,string>::iterator iter;
for(iter=maps.begin(); iter !=maps.end(); iter++)
{
cout<<iter->first<<" "<<iter->second<<endl;
}

cout<<"---------"<<endl;
}

int main()
{
map<int,string> mapstu;
mapstu.insert(pair<int,string>(1,"stu1"));

print(mapstu);

mapstu.insert(pair<int,string>(3,"stu3"));
print(mapstu);

mapstu.insert(pair<int,string>(7,"stu7"));
print(mapstu);

mapstu.insert(map<int,string>::value_type (5,"stu5"));
print(mapstu);

mapstu.insert(map<int,string>::value_type (2,"stu22"));
print(mapstu);

mapstu[2]="stu2";
print(mapstu);

mapstu[8]="stu8";
print(mapstu);

//for(int i=1;i<=mapstu.size();i++)
//	cout<<i<<" "<<mapstu[i]<<endl;
map<int ,string> ::iterator iter=mapstu.find(3);
if(iter !=mapstu.end())
	cout<<"found "<<iter->second<<endl;

map<int ,string> ::iterator iter1=mapstu.find(6);
if(iter1==mapstu.end())
	cout<<"no found"<<endl;

return 0;
}
