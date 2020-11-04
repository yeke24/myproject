#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool func(int i, int j)
{
    return i > j;
}

int cmp ( const void *a , const void *b )  
{  
return *(int *)a - *(int *)b;  
} 

int main()
{   
    int a[] = { 9,5,2,7,6,1,3 };
    sort(a, a + 7); //默认升序
    //qsort(a, 7, sizeof(a[0]),cmp);
    sort(a, a + 7,func); //降序
    for (int i = 0; i < 7; ++i)
    {
        cout << a[i];
    }
    cout << endl;

    int a1[]={ 1,2,3,4,5,6,7,8 };
    int a2[]={ 5,  7,  9,10 };

    vector<int> v1;
    vector<int> v2;

    v1.insert(v1.end(),a1,a1+8);
    v2.insert(v2.end(),a2,a2+4);
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    vector<int> v_intersection;

    set_intersection(v1.begin(), v1.end(),v2.begin(), v2.end(), back_inserter(v_intersection));
    
    //for (int n : v_intersection)
    //    cout << n << ' ';

    vector<int>::iterator itr;
    for(itr=v_intersection.begin(); itr!=v_intersection.end();itr++)
    {
        cout<<*itr<<" ";
    }
    cout<<endl;

    vector<int> v_difference;

    set_difference(v1.begin(), v1.end(), v_intersection.begin(), v_intersection.end(), inserter(v_difference, v_difference.begin()));
    //set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v_difference));

    for(itr=v_difference.begin(); itr!=v_difference.end(); itr++)
    {
        cout<<*itr<<" ";
    }
    cout << endl;

    vector<int> v_union;
    set_union(a.begin(), a.end(),b.begin(), b.end(), back_inserter(v_union));

    for(itr=v_union.begin(); itr!=v_union.end(); itr++)
    {
        cout<<*itr<<" ";
    }
    cout << endl;

   return 0;
}

