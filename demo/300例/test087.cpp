#include<iostream>
#include<stdlib.h>
#include<cstring>

using namespace std;

const int M=30;

void delzero(char *ch, int size)
{
   int len=size;

   for(int i=0;i<size;i++)
   {
       if(ch[i]==' ')
       {
           for(int j=i;j<size;j++)
   	   {
		ch[j]=ch[j+1];
	   }
  	   len--;  
   	   i--;
	}
   }
   ch=new char[len];
}

void  gdelzero(char *ch,int size)
{
int zeronum=0;

for(int i=0;i<size;i++)
{
   if(ch[i]==' ')
	zeronum++;
}

char *result=new char [size-zeronum];

int j=0;
for(int i=0;i<size&&zeronum>0;i++)
{
    if(ch[i]==' ')
    {	
	zeronum--;
    }
    else
    {
	result[j]=ch[i];
	j++;
    }	
}
strcpy(ch,result);
//return result;
}

int main()
{

char *ch_test;
ch_test=new char[M];

strcpy(ch_test,"ak dfl jak df    ");
cout<<"origin:"<<ch_test<<"!"<<endl;

int len=strlen(ch_test);
//char *te[30];
//ch_test=
gdelzero(ch_test,len);
cout<<"new:"<<ch_test<<"!"<<endl;

free(ch_test);
ch_test=NULL;

return 0;
}

