#include<stdio.h>
#include<stdlib.h>

int main()
{
    int **a;
    a=(int **)malloc(sizeof(int *)*3);
    
    int i=0, j=0;
 
    for (i=0; i<3; i++)
    {
        a[i] = (int*)malloc(sizeof(int)*5);
        for (j=0; j<5; j++)
        {
            *(*(a+i)+j)=j;
        }
    } 
 
 
    for (i=0; i<3; i++)
    {
        for (j=0; j<5; j++)
        {
            printf("%d\t", *(*(a+i)+j));
        }
        printf("\n");
    }
     
 
    delete[] a;
    return 0;

}
