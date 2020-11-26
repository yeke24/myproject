#include<iostream>
using namespace std;

int binarySearch(int *arr, int n, int key)
{
int left=0;
int right=n-1;

while(left<=right)
{
   int mid=(left+right)/2;
   //int mid=left+((right-left)>>1);
   //
   if(arr[mid]>key)
   {
      right=mid-1;
   }
   else if(arr[mid]<key)
   {
	  left=mid+1;
   }
   else
	  return mid;

}
return -1;
}

int main()
{
int a[4]={1,3,5,7};
int n;
cin>>n;
cout<<binarySearch(a,4,n)<<endl;

return 0;
}

