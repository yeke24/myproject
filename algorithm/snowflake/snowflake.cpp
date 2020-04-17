#include "snowflake.h"

#define   sequenceMask  (-1L ^ (-1L << 12L))

pthread_mutex_t snowflake_mutex = PTHREAD_MUTEX_INITIALIZER;
snowflake* snowflake::_instance = NULL;
snowflake* snowflake::instance()
{
    if(NULL == _instance)
    {
        pthread_mutex_lock(&snowflake_mutex);
        if(NULL == _instance)
        {
            _instance = new snowflake();
        }
        pthread_mutex_unlock(&snowflake_mutex);
    }
    return _instance;
}

snowflake::snowflake()
{
    info_.last_stamp = 0;
}

snowflake::~snowflake()
{

}

void snowflake::set_workid(int workid)
{
    info_.workid = workid;
}

pid_t snowflake::gettid( void )
{
    return syscall( __NR_gettid );
}

uint64_t snowflake::get_curr_ms()
{
    struct timeval time_now;
    gettimeofday(&time_now,NULL);
    uint64_t ms_time = time_now.tv_sec*1000+time_now.tv_usec/1000;
    
    return ms_time;
}

uint64_t snowflake::wait_next_ms(uint64_t lastStamp)
{
    uint64_t cur = 0;
    do
    {
        cur = get_curr_ms();
        
    } while (cur <= lastStamp);
    
    return cur;
}

int snowflake::atomic_incr(int id)
{
    __sync_add_and_fetch( &id, 1 );
    return id;
}

uint64_t snowflake::get_unique_id()
{
    uint64_t  uniqueId = 0;
    uint64_t nowtime = get_curr_ms();
    uniqueId = nowtime<<22;
    uniqueId |= (info_.workid&0x3ff)<<12;

/*    if (nowtime < info_.last_stamp)
 *        {
 *                writeLog("exit");
 *                        throw;
 *                            }
 *                            */
    
    if (nowtime == info_.last_stamp)
    {
        info_.seqid = atomic_incr(info_.seqid)& sequenceMask;
        if (info_.seqid == 0)
        {
            nowtime = wait_next_ms(info_.last_stamp);
        }
    }
    else
    {
        info_.seqid  = 0;
    }
    
    info_.last_stamp = nowtime;
    uniqueId |= info_.seqid;

    return uniqueId;
}

