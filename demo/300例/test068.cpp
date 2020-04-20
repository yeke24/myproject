#include<iostream>
#include<string>

using namespace std;

int main()
{
   string str="hello";
   char *ch="world";
   char *ch1="c++";

   string str1;

   str1=str+ch;
   cout<<str1<<endl;
   cout<<str1.append(ch1)<<endl;
//   cout<<str1<<endl;

return 0;
}
