#include<iostream>
#include<string.h>

using namespace std;

char *strupr(char *str){
    char *orign=str;
    for (; *str!='\0'; str++)
        *str = toupper(*str);
    return orign;
}

char *strdownr(char *str)
{
	char *origin=str;
	for(;*str!='\0';str++)
		*str=tolower(*str);

	return origin;
}

int main()
{
   char str[]="Hello world";
   
   cout<<str<<endl;
   cout<<strupr(str)<<endl; 
   cout<<strdownr(str)<<endl;

return 0;
}

