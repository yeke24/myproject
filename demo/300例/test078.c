#include<stdio.h> 

void main()
{
   const int len = 100;
    int* ptr = (int*)(&len);
 
    (*ptr) = 101;
    printf("%d\n", len);
    printf("%d\n", *ptr);
}
