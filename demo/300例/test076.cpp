#include<iostream>
using namespace std;

void decrease(void *data, int psize)
{
   switch(psize)
   {
	case 1:
		char * pchar;
		pchar=(char *)data;
		--(*pchar);
		break;

	case sizeof(int):
		int * pint;
		pint=(int *)data;
		--(*pint);
		//*pint=4;
		break;
	default:
		;
    }
}


int main()
{
char a='d';
int b=102;

decrease(&a,sizeof(char));
decrease(&b,sizeof(int));

cout<<a<<","<<b<<endl;

return 0;
}
