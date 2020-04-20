#include <iostream>
#include <list>
using namespace std;


void Get_Sum(int sum,int n,int a[],list<int>& lst)
{
    if(sum<=0 || n<0)return;

    if(sum==a[n])
    {
        lst.push_back(a[n]);

        list<int>  ::  iterator it = lst.begin();
        while(it!=lst.end())
        {   
            cout<<*it<<" ";
          it++;
        }
        cout<<endl;
    }
    lst.push_back(a[n]);
    Get_Sum(sum-a[n],n-1,a,lst);
    lst.pop_back();
    Get_Sum(sum,n-1,a,lst);
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9};
    list<int> list;
    Get_Sum(5,sizeof(a)/sizeof(int)-1,a,list);
    return 0;
}
