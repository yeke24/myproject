#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main()
{
int result;
srand((int)time(0));
int count[6]={0};

for(int i=0;i<1000000;i++)
{
   result=1+(int)(6.0*rand()/(RAND_MAX+1.0));

   switch(result)
   {
	case 1:
		count[0]++;
		break;
	case 2:
		count[1]++;
		break;
	case 3:
		count[2]++;
		break;
	case 4:
		count[3]++;
		break;
	case 5:
		count[4]++;
		break;
	case 6:
		count[5]++;
		break;
	default:
		;
   }

}
cout<<"1-6出现的概率分别为:"<<endl;
for(int i=0;i<6;i++)
{
	cout<<count[i]/1000000.0<<" ";
}

cout<<endl;
return 0;
}
