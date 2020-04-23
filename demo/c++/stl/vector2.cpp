#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

struct Rect
{
Rect(){
id=2;
len=1;
width=0;
}

int id;
int len;
int width;

bool operator < (const Rect & a) const
{
if(id!=a.id)
	return id<a.id;
else
	if(len!=a.len)
		return len<a.len;
	else
		return width<a.width;

}

};

int main()
{
Rect rect;
cout<<rect.id<<rect.len<<endl;

vector<Rect> v;
v.push_back(rect);

vector<Rect>::iterator iter1=v.begin();
cout<<(*iter1).id<<" "<<(*iter1).len<<endl;

rect.id=1;
rect.len=2;
v.push_back(rect);

vector<Rect>::iterator iter=v.begin();
cout<<(*iter).id<<" "<<(*iter).len<<endl;
iter++;
cout<<(*iter).id<<" "<<(*iter).len<<endl;

rect.id=2;
rect.len=2;
v.push_back(rect);

for(vector<Rect>::iterator it=v.begin();it!=v.end();it++)
{
cout<<(*it).id<<"--"<<(*it).len<<endl;
}

sort(v.begin(),v.end());

for(vector<Rect>::iterator it=v.begin();it!=v.end();it++)
{
cout<<(*it).id<<"--"<<(*it).len<<endl;
}
return 0;
}
