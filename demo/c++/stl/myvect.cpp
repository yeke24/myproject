#include<iostream>
#include<vector>
using namespace std;

int main()
{
vector<string> vbaglist;
string str="10,101,10111"

vbaglist.push_back("10");
vbaglist.push_back("111");
vbaglist.push_back("10111");

vector<string>::iterator ite;

for(ite=vbaglist.begin();ite!=vbaglist.end();ite++)
{
	cout<<*ite<<endl;
}


return 0;
}
