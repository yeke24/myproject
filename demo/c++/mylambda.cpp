#include<iostream>
using namespace std;
      
typedef enum
{     
    add = 0,
    sub,
    mul,
    divi
}type;
      
int main()
{     
    int a = 10;
    int b = 20;
      
    auto func = [=](type i)->int {
        switch (i)
        {
            case add:
                return a + b;
            case sub:
                return a - b;
            case mul:
                return a * b;
            case divi:
                return a / b;
        }
    };
      
    cout<<func(add)<<endl;
}
