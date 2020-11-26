#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<future>
#include <semaphore.h>

using namespace std;


mutex data_mutex;
condition_variable data_var;
bool label=false;

void funA()
{
	unique_lock<mutex> ulock(data_mutex);
	for(int i=0; i<10;i+=2)
	{
		cout<<i<<i+1;
		data_var.notify_one();
		label=true;
		data_var.wait(ulock,[]{return !label;});
	}
}

void funB()
{
	unique_lock<mutex> ulock(data_mutex);
	char a[10]={'A','B','C','D','E','F','H','I','J','K'};

	for(int i=0;i<10;i+=2)
	{
		data_var.wait(ulock,[]{return label;});
		cout<<a[i]<<a[i+1];
		label=false;
		data_var.notify_one();
	}
}

mutex m1, m2;

void funC()
{
	for(int i=0; i<10;i+=2)
	{
		m1.lock();
		cout<<i<<i+1;
		m2.unlock();
	}
}

void funD()
{
	char a[10]={'A','B','C','D','E','F','H','I','J','K'};

	for(int i=0;i<10;i+=2)
	{
		m2.lock();
		cout<<a[i]<<a[i+1];
		m1.unlock();
	}
}

promise<void> p1;
promise<void> p2;

void funE()
{
	for(int i=0; i<10;i+=2)
	{
		p2.get_future().wait();
		cout<<i<<i+1;
		p1.set_value();
	}
}

void funF()
{
	char a[10]={'A','B','C','D','E','F','H','I','J','K'};

	for(int i=0;i<10;i+=2)
	{
		p1.get_future().wait();
		cout<<a[i]<<a[i+1];
		p2.set_value();
	}
}

sem_t firstJobDone;
sem_t secondJobDone;


void funI()
{
	for(int i=0; i<10;i+=2)
	{
		sem_wait(&secondJobDone);
		cout<<i<<i+1;
		sem_post(&firstJobDone);
	}
}

void funJ()
{
	char a[10]={'A','B','C','D','E','F','H','I','J','K'};

	for(int i=0;i<10;i+=2)
	{
		sem_wait(&firstJobDone);
		cout<<a[i]<<a[i+1];
		sem_post(&secondJobDone);
	}
}


int main()
{
	
	thread tA(funC);
	thread tB(funD);

	//m2.lock();

	tA.join();
	tB.join();
	
	p2.set_value();
	//sem_post(&secondJobDone);

	cout<<endl;
	return 0;	
}
