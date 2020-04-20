#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc , const char *argv[])
{
char * src ="hello world";
char * dest=NULL;

int len=strlen(src);

dest=(char *)malloc(len+1);

if(NULL==dest)
{
printf("malloc is fail");
return -1;

}

char *d=dest;
char *s=&src[len-1];

while(len--!=0)
     *d++=*s--;
*d='\0';
puts(dest);

free(dest);
dest=NULL;

return 0;

}

