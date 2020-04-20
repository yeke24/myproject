#include<stdlib.h>
#include<stdio.h>
#include<cstring>
//#include<cstdlib>//注意。itoa函数要包含这个头文件
using namespace std;
int main()
{
    int a=0x12;
    printf("八进制  %o\n",a);
    printf("十六进制 %x\n",a);
    printf("十进制 %d\n",a);
    char s[40];//要转换成的字符数组
    //itoa(a,s,2);//itoa转为二进制
    //printf("二进制 %s\n",s);//s就是你转换成的数组
    //itoa(a,s,3);//转为三进制 
    snprintf(s, sizeof(s), "%d", a);
    printf("十进制 %s\n",s);
    return 0; 
 } 

