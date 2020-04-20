#include<iostream>  
#include <typeinfo>  
#include<stdlib.h>
using namespace std;  

class Class1{};
class Class2:public Class1{};
void fn0();
int fn1(int n);

int main(void)  
{  
    int a = 10;
    int* b = &a;
    float c;
    double d;
    int i=1;

    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    cout << typeid(c).name() << endl;
    cout << typeid(d).name() << endl;
    cout << typeid(Class1).name() << endl;
    cout << typeid(Class2).name() << endl;
    cout << typeid(fn0).name() << endl;
    cout << typeid(fn1).name() << endl;
    cout << typeid(typeid(a).name()).name() << endl;
    cout<<typeid(i).name()<<endl;   
 
    if(typeid(Class1).name()==typeid(Class2).name())
	{
		cout<<"=="<<endl;
	}

    //system("pause");
    return 0;
}  

