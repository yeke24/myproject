#include<iostream>
#include<map>
#include<set>
#include<string>

using namespace std;

int main()
{
    map<int, string> map1;
    
     map1.insert(pair<int, string>(1, "teacher01"));
    map1.insert(pair<int, string>(2, "teacher02"));

	 //map1.insert(pair<int, string>(1, "teacher03"));

	map<int, string>::iterator it=map1.find(1);
	
	if(it != map1.end())
	{
	       it->second+=",";
                
                //str+="teacher03";
	
		it->second+="teacher03";
	}

    //map<int, string>::iterator it; 
    for(it = map1.begin(); it != map1.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;   //map的遍历,跟pair(对组)一样,first表示第一个(键key),
	//second表示第二个(值value)；
    }
    cout<<"遍历结束"<<endl;


return 0;
}
