#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
pid_t pid;
pid=fork();

if(pid<0)
{
printf("fail to fork");
exit(-1);
}

else if(pid==0)
{
printf("it is a sub-process, pid:%u,ppid:%u\n",getpid(),getppid());
//sleep(2);
}
else
{
printf("parent, pid:%u, sub-pid:%u\n",getpid(),pid);
sleep(2);
}

return 0;
}
