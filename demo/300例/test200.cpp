#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

int main()
{
string str;

for(int i=1;i<5;i++)
{
	if(!str.empty())
	{
		str+=",";
	}
	char ch[10];
	snprintf(ch, sizeof(ch), "%d", i);
	str+=ch;
}

cout<<str<<endl;

return 0;
}

