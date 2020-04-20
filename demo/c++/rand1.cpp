#include<iostream>
#include<stdlib.h>
#include <sys/time.h>
#include <algorithm>
#include <math.h>
#include <unistd.h>

using namespace std;

int main()
{
for(int i=0;i<10;i++)
{

    srand((unsigned)time(NULL)); 
    int num = (rand() % (999999-100000+1))+ 100000; 
    cout<<num<<endl;
	usleep(400000);
	//usleep(99999);
}
return 0;
}
