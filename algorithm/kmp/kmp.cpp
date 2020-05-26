#include<iostream>
#include<string.h>

using namespace std;

int * getnext(char* p,int &plen)
{  
   plen=strlen(p);
   
   int *next=new int[plen];
   
   next[0]=-1;
   int k=-1;
   int j=0;
   
   while(j<plen-1)
   {    
        if(k==-1 || p[j]==p[k])
        {       
                j++;
                k++;
                next[j]=k;
        }
        else    
                k=next[k];
   }
   
   return next;
}

int * getnextval(char* p,int &plen)
{  
   plen=strlen(p);
   
   int *next=new int[plen];
   
   next[0]=-1;
   int k=-1;
   int j=0;
   
   while(j<plen-1)
   {    
        if(k==-1 || p[j]==p[k])
        {       
                j++;
                k++;
                
                if(p[j]!=p[k])
                	next[j]=k;
                else //出现p[j] = p[ next[j]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]
                	next[j]=next[k]; 
        }
        else    
                k=next[k];
   }
   
   return next;
}

int kmp(char * s, char* p)
{
int slen=strlen(s);
int i=0;
int j=0;
int plen;

int *next =getnext(p,plen);
//int *next =getnextval(p,plen); //优化的

while(i<slen && j<plen)
{
    if(j==-1 || s[i]==p[j])
    {
        i++;
        j++;
    }
    else //如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]
        j=next[j];
}
delete [] next;

if(j==plen)
        return i-j;
else
        return -1;

}

int main()
{
char s[] = "bacbababadababacambabacaddababacasdsd";
char p[] = "ababaca";

int pos1=kmp(s,p);
int pos2=strstr(s,p)-s;

cout<<pos1<<endl;
cout<<pos2<<endl;
return 0;
}