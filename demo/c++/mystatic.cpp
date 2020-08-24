#include<iostream>
#include<stdio.h>
#include<string>
#include <pthread.h>
#include <cstdlib>

#define NUM_THREADS 2

using namespace std;

void* generate_initializer(void * str)
{
        static char sep='#';
        printf("%c %s", sep, "yyyy");
        sep=',';
}

void generate_initializer1(const char * str)
{
        static char sep=' ';
        printf("%c %s", sep, str);
        sep='#';
}

int main()
{
        string str="yeke";
        generate_initializer1(str.c_str());

        string str1="yeye";
        generate_initializer1(str1.c_str());

        string str2="keke";
        generate_initializer1(str2.c_str());

        cout<<endl;

    pthread_t tids[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; ++i)
    {

        int ret = pthread_create(&tids[i], NULL, generate_initializer, NULL);
        if (ret != 0)
        {
           cout << "pthread_create error: error_code=" << ret << endl;
        }

        ret = pthread_create(&tids[i], NULL, generate_initializer, NULL);
        if (ret != 0)
        {
           cout << "pthread_create error: error_code=" << ret << endl;
        }
    }
    //cout<<endl;
    
    pthread_exit(NULL);

	return 0;
}