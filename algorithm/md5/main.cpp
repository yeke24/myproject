#include <stdio.h>
#include<string.h>
#include "md5.h"

int main(int argc,char* argv[])
{
    if(2 != argc)
        return 0;
    char sResult[33];
    memset(sResult,0x00,sizeof(sResult));
    MD5String(argv[1],sResult);
    printf("[md5(%s)]=[%s]\n",argv[1],sResult);
    return 0;
}
