#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
char* src="abcd";
int len=strlen(src);

char* dest=(char*)malloc(len+1);
if(dest==NULL)
{
  printf("malloc is fail");
  return -1;
}

char *d=dest;
char *s=&src[len-1];

while(len--!=0)
	*d++=*s--;
*d='\0';

printf("d:%s dest:%s",d,dest);
free(dest);

return 0;
}

