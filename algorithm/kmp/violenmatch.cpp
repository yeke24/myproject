#include<iostream>
#include<string.h>

using namespace std;

int violenMatch(char* s, char* p)
{
	int slen=strlen(s);
	int plen=strlen(p);

	int i=j=0;
	while(i<slen && j<plen)
	{
		if(s[i]==p[j])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+1;
			j=0;
		}
	}

	if(j==plen)
		return i-j;
	else
		return -1;
}

int main()
{


	return 0;
}