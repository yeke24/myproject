#ifndef __SNOWFLAKE_H__
#define __SNOWFLAKE_H__

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>
#include <linux/unistd.h>
#include <sys/syscall.h>
#include <errno.h>
#include<linux/types.h>
#include<time.h>
#include <stdint.h>
#include <sys/time.h>

 
 /*     snowflake 
 *     
 *     ID 生成策略 
 *     毫秒级时间41位+机器ID 10位+毫秒内序列12位。 
 *     0 41 51 64 +-----------+------+------+ |time |pc |inc | +-----------+------+------+ 
 *     前41bits是以微秒为单位的timestamp。 
 *     接着10bits是事先配置好的机器ID。 
 *     最后12bits是累加计数器。 
 *     macheine id(10bits)标明最多只能有1024台机器同时产生ID，sequence number(12bits)也标明1台机器1ms中最多产生4096个ID;
 *     注意点，因为使用到位移运算，所以需要64位操作系统，不然生成的ID会有可能不正确 
 *   */                                           

// 支持原子自增操作。
// 1.多线程情况下，可以将workid进行移位加上线程ID。
// 2.采用单例 保证多线程情况的唯一

class snowflake
{
    public:
        static snowflake* instance();

        snowflake();

        ~snowflake();
        
    public:
        void set_workid(int workid);
        
        pid_t gettid( void );
        
        uint64_t get_curr_ms();
        
        uint64_t wait_next_ms(uint64_t lastStamp);
        
        int atomic_incr(int id);
        
        uint64_t get_unique_id();

    private:
        struct seq_info
        {
            int         global_int:12;
            uint64_t    last_stamp;
            int         workid;
            int         seqid;
        };
        
        seq_info info_;
        static snowflake* _instance;
};

#endif

