#ifndef LOCK_H_
#define LOCK_H_
 
#include <unistd.h>
 
//normal lock
class Lock {
public:
    Lock();
    virtual ~Lock();
    void lock();
    void unlock();
protected:
    pthread_mutex_t  mutex_t;
};
 
//lock with condition
class Condition_Lock:public Lock{
public:
    Condition_Lock();
    virtual ~Condition_Lock();
    int wait();
    int wait_time(int sec); //wait seconds
    void signal();
    void broadcast();
private:
    pthread_cond_t cond;
};
 
//read-write lock with reading first
class RW_Lock{
public:
    RW_Lock();
    ~RW_Lock();
    void rd_lock();
    void rd_unlock();
    void wt_lock();
    void wt_unlock();
private:
    int m_stat;
    Condition_Lock c_lock;
};
 
//read-write lock with writing first
class RW_Lock_w
{
public:
    RW_Lock_w();
    void rd_lock();
    void rd_unlock();
    void wt_lock();
    void wt_unlock();
private:
    int rd_cnt;
    Lock r_lock;
    Lock w_lock;
};
 
#endif //LOCK_H_