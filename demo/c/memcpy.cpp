
//error
void* memcpy(void* dest, void* source, size_t count)
{
	void* ret = dest;

  	//copy from lower address to higher address

  	while (count--)
		*dest++ = *source++;   //不知道两个指针的类型，不可以这样自加。
	
	return ret;
}

void* memcpy(void* dest, void* source, size_t count)
{
    char *ret = (char *)dest;

    char *dest_t = ret;

    char *source_t = (char *)source;

    while (count--){
        *dest_t++ = *source_t++;
    }  

	return ret;
}

void * memcpy(void *dest, const void *src, size_t count)  
{  
    if (dest == NULL || src == NULL)  
          return NULL;  
    char *pdest = static_cast <char*>(dest);  
    const char *psrc  = static_cast <const char*>(psrc);  
    int n = count;  
      
    if (pdest > psrc && pdest < psrc+count)  
    {  
        for (size_t i=n-1; i != -1; --i)  
        {  
                pdest[i] = psrc[i];  
        }  
    }  
    else  
    {  
        for (size_t i= 0; i < n; i++)  
        {  
                pdest[i] = psrc[i];  
        }  
    }  
      
    return dest;  
}

void* my_memcpy(void* dest,const void* src,size_t count)
{
	char* psrc=NULL;
	char* pdest=NULL;
	if(NULL==src&&NULL==dest)
		return NULL;
	if(src<dest&&(char*)src+count>(char*)dest)//从后往前拷贝
	{
		psrc=(char*)src+count-1;
		pdest=(char*)dest+count-1;
		while(count--)
		{
			*pdest--=*psrc--;
		}
	}
	else
	{
		psrc=(char*)src;
		pdest=(char*)dest;
		while(count--)
		{
			*pdest++=*psrc++;
		}
	}
	return dest;
}

