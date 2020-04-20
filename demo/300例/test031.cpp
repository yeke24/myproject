#include<iostream>
using namespace std;

bool  binary_search(int *arr,int len, int value)
{
int left=0;
int right=len-1;

while(left<=right)
{       
        int mid=left+((right-left)>>1);

        if(arr[mid]>value)
                right=mid-1;
        else if(arr[mid]<value)
                left=mid+1;
        else
                return true;
}
return false;
}

int main()
{
int a[10]={0,1,2,3,4,5,6,7,8,9};

cout<<binary_search(a,9,8)<<endl;

return 0;
}

