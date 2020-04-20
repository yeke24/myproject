#include<iostream>
using namespace std;

int * max_min(int *a, int num)
{
int min_max[2];
min_max[0]=min_max[1]=a[0];

for(int i=1;i<num;i++)
{
	if(min_max[0]<a[i])
	{
		min_max[0]=a[i];
	}
	
	if(min_max[1]>a[i])
	{
		min_max[1]=a[i];
	}

}
return min_max;
}

int main()
{
int aa[10]={34,12,24,1,1,4,6,7,58,9};

cout<<"max:"<<max_min(aa,10)[0]<<endl;
cout<<"min:"<<max_min(aa,10)[1]<<endl;

return 0;
}

