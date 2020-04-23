#include<iostream>

using namespace std;

void swap1(int &a,int &b)
{
	int t;
	t=a;
	a=b;
	b=t;
}

void quicksort(int *arr, int left, int right )
{
	int i,j,t;
	if(left<right)
	{
		i=left;
		j=right;
		t=arr[left];

		while(i<j)
		{
			while(i<j && arr[j]>t)
				j--;
			if(i<j)
			{
				int m=arr[i];
				arr[i]=arr[j];
				arr[j]=m;
				i++;
			}
			
			while(i<j&&arr[i]<=t)
				i++;
			if(i<j)
			{
				int m=arr[j];
                arr[j]=arr[i];
                arr[i]=m;
				j--;
			}
		}
				
		arr[i]=t;
		quicksort(arr,0,i-1);
		quicksort(arr,i+1,right);
	}

}

void quicksort2(int * arr, int left ,int right)
{
	int i,j;
	if(left<right)
	{
		i=left+1;
		j=right;
		while(i<j)
		{
			if(arr[i]>arr[left])
			{
				swap1(arr[i],arr[j]);
				j--;
			}
			else
				i++;
		}
		if(arr[i]>=arr[left]) //回溯                  
		{
			i--;
		}
		
		swap1(arr[left],arr[i]);
		quicksort2(arr,left,i-1);
		quicksort2(arr,i+1,right);
	}

}

void bubblesort(int * arr,int size)
{
int i,j,tmp;
for(i=0;i<size-1;i++)
    for(j=0;j<size-i-1;j++)
	if(arr[j]>arr[j+1])
		{
			tmp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=tmp;
		}

}

void selectsort(int *arr, int size)
{
int i,j,tmp;
for(i=0;i<size-1;i++)
{
  int  k=i;	
   for(j=i;j<size;j++)
     {
	if(arr[j]<arr[k])
	{k=j;}
     }
     tmp=arr[i];
     arr[i]=arr[k];
     arr[k]=tmp;
}

}

void insertsort(int * arr , int size)
{
int i,j,tmp;
for(i=1;i<size;i++)
{
	if(arr[i]<arr[i-1])
		{
			tmp=arr[i];
			for(j=i-1;j>=0&&arr[j]>tmp;j--)
			{arr[j+1]=arr[j];}
			arr[j+1]=tmp;
		}

}

}
 
int main()
{
int arr1[10]={5,3,6,4,0,8,2,7,9,1};

//quicksort(arr1,0,9);
//quicksort2(arr1,0,9);
//bubblesort(arr1,10);
//selectsort(arr1,10);
insertsort(arr1,10);

for(int i=0;i<10;i++)
{
cout<<arr1[i]<<endl;
}


return 0;
}

