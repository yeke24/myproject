#include<iostream>
using namespace std;

int main(int argc, char ** argv)
{
for(int i=0;i<argc;i++)
{
	cout<<"Argument "<<i<<" is "<<argv[i]<<endl;
}

if(argc==5)
	cout<<"一共有4个命令需要执行"<<endl;
else
	cout<<"不是四个命令"<<endl;

return 0;
}
