#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
int ret;
//ret=alarm(5);
while(1)
{
printf("I have been waken up.\n",ret);
pause();

printf("I have been waken up.\n",ret);
}

} 
