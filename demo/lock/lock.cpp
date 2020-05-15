#include <pthread.h>
#include <sys/time.h>
#include "lock.h"
 
Lock::Lock() {
    pthread_mutex_init(&mutex_t,NULL);
}
 
void Lock::lock() {
    pthread_mutex_lock(&mutex_t);
}
 
void Lock::unlock() {
    pthread_mutex_unlock(&mutex_t);
}
 
Lock::~Lock() {
    pthread_mutex_destroy(&mutex_t);
}

int Condition_Lock::wait() {
    return pthread_cond_wait(&cond,&mutex_t);
}
 
Condition_Lock::Condition_Lock():Lock() {
    pthread_cond_init(&cond,NULL);
}
 
Condition_Lock::~Condition_Lock() {
    pthread_cond_destroy(&cond);
}
 
void Condition_Lock::broadcast() {
    pthread_cond_broadcast(&cond);
}
 
void Condition_Lock::signal() {
    pthread_cond_signal(&cond);
}
 
int Condition_Lock::wait_time(int sec) {
    struct timespec tp;
 
    struct timeval tv;
    gettimeofday(&tv,NULL);
    tp.tv_sec=tv.tv_sec+sec;
    tp.tv_nsec=tv.tv_usec*1000;
 
    return pthread_cond_timedwait(&cond,&mutex_t,&tp);
}
 

RW_Lock::RW_Lock():m_stat(0){
}
 
RW_Lock::~RW_Lock() {
 
}
 
void RW_Lock::rd_lock() {
    c_lock.lock();
    while(m_stat<0)
        c_lock.wait();
 
    m_stat++;
    c_lock.unlock();
}
 
void RW_Lock::rd_unlock() {
    c_lock.lock();
    m_stat--;
    c_lock.signal();
    c_lock.unlock();
}
 
 
void RW_Lock::wt_lock() {
    c_lock.lock();
    while(m_stat>0)
        c_lock.wait();
 
    m_stat=-1;
}
 
void RW_Lock::wt_unlock() {
    m_stat= 0;
    c_lock.broadcast();
    c_lock.unlock();
}

RW_Lock_w::RW_Lock_w() {
}
 
void RW_Lock_w::rd_lock() {
    r_lock.lock();
    if(++rd_cnt==1)
        w_lock.lock();
    r_lock.unlock();
}
 
void RW_Lock_w::rd_unlock() {
    r_lock.lock();
    if(--rd_cnt==0)
        w_lock.unlock();
    r_lock.unlock();
}
 
 
void RW_Lock_w::wt_lock() {
    w_lock.lock();
}
void RW_Lock_w::wt_unlock() {
    w_lock.unlock();
}