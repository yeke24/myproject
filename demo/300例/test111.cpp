#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;


void generate_lower()
{
   char lower;
   int lower_index;
   lower_index=1+(int)(26.0*rand()/(RAND_MAX+1.0));
   lower=char(lower_index+96);
   cout<<lower;
}

void generate_upper()
{
   char upper;
   int upper_index;
   upper_index=1+(int)(26.0*rand()/(RAND_MAX+1.0));
   upper=(char)(upper_index+64);
   cout<<upper;
}

void generate_number()
{
   int number;
   number=0+(int)(9.0*rand()/(RAND_MAX));
   cout<<number;
}

int main()
{
srand((int)time(0));
int num;
int upper;
int lower;
int number;

while(1)
{
cout<<"please cin what number of the code "<<endl;
cin>>num;
cout<<"on the "<<num<<" upper,lower,number has:"<<endl;
cin>>upper>>lower>>number;

while(upper)
{
   generate_upper();
   upper--;
}

while(lower)
{
   generate_lower();
   lower--;
}

while(number)
{
   generate_number();
   number--;
}

cout<<endl;
int x;
cout<<"if you want to keep cin 1,not 2"<<endl;
cin>>x;
if(x==2)
{
cout<<"quit"<<endl;
break;
}

}

#if 0
cout<<RAND_MAX<<endl;
cout<<rand()<<endl;
int a=(int)(26.0*rand()/(RAND_MAX));
cout<<a<<endl;
int b=(int)(9.0*rand()/(RAND_MAX));
cout<<b<<endl;
#endif
return 0;
}
