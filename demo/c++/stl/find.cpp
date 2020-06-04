#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> v;
	int values[]={1,3,5,7};

	v.insert(v.end(),values+1,values+3);
	v.push_back(9);
	v.insert(v.begin(),1,2);
	v.erase(v.begin()+2);
	v.erase(v.begin());
	v.insert(v.begin()+1,4);
	v.insert(v.end()-1 ,4, 6);
	v.pop_back();

	vector<int>::iterator iter=find(v.begin(),v.end(),3);
	cout<<*iter<<"--3--"<<endl;

	list<string> lis1;

	lis1.push_back("22");
	lis1.push_back("yeke");

	lis1.push_front("yeye");
	lis1.push_front("keke");

	lis1.insert(lis1.begin(), "100");
	lis1.insert(lis1.begin(), 2, "kk");

	lis1.erase(--lis1.end());
	lis1.pop_front();
	lis1.pop_back();

	list<string>::iterator itr;
	cout<<"<<<<<>>>>>"<<endl;
	itr=find(lis1.begin(),lis1.end(),"yeye");
	cout<<*itr<<"--yeye--"<<endl;
	
	cout<<"#######"<<endl;
	for(itr=lis1.begin(); itr!=lis1.end(); itr++)
	{
		cout<<*itr;
	}
	cout<<endl;
	cout<<"#######"<<endl;

	//lis1.sort();
	lis1.clear();

	return 0;
}