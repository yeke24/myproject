#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <unistd.h>
#include <glog/logging.h>
#include <string.h>
#include "json.h"
#include "redis_pool.h"
#include "database.h"

#include "id_control_service.h"
extern RedisPool glbRedis;
extern DatabaseMysql glbDatabaseAccount;
static const char* DISTRIBUTE_MUTEX_LOCK_KEY = "id_gen_distributed_mutex_"; //分布式锁需要的键
static const char* DISTRIBUTE_ID_LIST_KEY = "id_gen_numid_list_";      //分布式id列表

IdControlService::IdControlService(int id_type)
{
    m_id_type = id_type;
    stringstream ss;
    ss << id_type;
    m_mutex_val = "" ;
    m_mutex_key = DISTRIBUTE_MUTEX_LOCK_KEY + ss.str();
    m_id_list_key = DISTRIBUTE_ID_LIST_KEY + ss.str();
}

int IdControlService::distribute_mutex_lock(const string& mutex, int time_out)
{
    m_mutex_val = getMutexValue();
    string resp = "";
    int try_cnt = 0;
    while(true)
    {
        if(try_cnt >= 1)
            return -1;
        ++try_cnt;
        
        int rc = glbRedis.wrapper(resp, "SET %s %s NX PX %d" , mutex.c_str(), m_mutex_val.c_str(), time_out);
        if(  rc == 0 && resp == "OK")
            break;
        else if( rc < 0 )
        {
            LOG(ERROR)<<"lock redis error rc="<<rc;
            return -1;
        }
        usleep(2000);
    }
    return 0;
}
int IdControlService::distrubute_mutex_unlock(const string& mutex)
{
    const char format[] = "local val = redis.call('get', '%s'); if val == '%s' then redis.call('del', '%s'); return 'DODEL'; else return 'DONOT'; end";
    char script[512] = {0};
    string resp = "";
    snprintf(script, 256, format, mutex.c_str(), m_mutex_val.c_str(),  mutex.c_str());
    int rc = glbRedis.wrapper(resp, "EVAL %s 0" , script);
    if( rc < 0 )
    {
        LOG(ERROR)<<"unlock redis error rc="<<rc<<" str="<<resp;
    }    
    return 0;
}

const string IdControlService::getMutexValue()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand((int)tv.tv_usec);
    int num = rand();
    stringstream ss;
    ss << num;
    return ss.str();
}



uint32_t IdControlService::getId()
{
    uint32_t id = 0;
    string resp = "";
    int rc = glbRedis.wrapper(resp, "LPOP %s" , m_id_list_key.c_str() );
    if(rc == 0)
    {
        id = strtoul(resp.c_str(), NULL, 0);
    }
    else if( rc == 1)
    {

        id = pushIdList();
        if(id == 0) //try again
        {
            rc = glbRedis.wrapper(resp, "LPOP %s" , m_id_list_key.c_str() );
            if(rc == 0)
            {
                id = strtoul(resp.c_str(), NULL, 0);
            }
        }
        return id;
    }
    else
    {
        LOG(INFO)<<"IdControlService-" << __LINE__ << ":LPOP ERROR rc=" << rc << " key=["<<m_id_list_key << "]";
    }
    return id;
}


int IdControlService::SqlGetIdValue(Json::Value& val, int id_type)
{
    int num = 0;
	stringstream ss;
	ss.str("");
	ss <<"SELECT Fuse, Fvalue, Flen FROM t_id_generate where Fuse = " << id_type;
    QueryResult* result = glbDatabaseAccount.Query(ss.str().c_str()); 
    if (result)
    {
        Field* field = result->Fetch();
        val["type"] = atoi(field[0].GetString()) ;
        val["value"] = atoi(field[1].GetString()) ;
        val["len"] = atoi(field[2].GetString()) ;
        num = 1;
    }
    SAFE_DELETE_PTR(result);
    return num;
}

bool IdControlService::SqlUpdateIdValue( int id_type, int len)
{
    time_t ts = time(NULL);
    bool result= glbDatabaseAccount.Execute("UPDATE t_id_generate SET Fvalue = Fvalue + %d, Fmtime = %d where Fuse = %d ", len, ts, id_type);
    return result;

}

uint32_t IdControlService::pushIdList()
{
    uint32_t id = 0;
    string resp = "";
    int rc = 0;
    long long int stt = getTimeMs();
    rc = distribute_mutex_lock(m_mutex_key, 30000);
    if( rc < 0)
        return 0;
    long long int ett = getTimeMs();
    if((ett - stt) > 2500) //超时
    {
        distrubute_mutex_unlock(m_mutex_key);
        LOG(INFO) << "IdControlService:get lock timeout";
        return 0;
    }
    rc = glbRedis.wrapper(resp, "LPOP %s" , m_id_list_key.c_str() );
    if(rc == 0)
    {
        id = strtoul(resp.c_str(), NULL, 0);
        distrubute_mutex_unlock(m_mutex_key);
        return id;
    }
    if(rc < 0)
    {
        LOG(INFO)<<"IdControlService-"<<__LINE__<<":LPOP error:rc=" << rc << " str="<<resp;
        distrubute_mutex_unlock(m_mutex_key);
        return 0;
    }
    Json::Value idInfo(Json::objectValue);
    rc = SqlGetIdValue(idInfo, m_id_type);
    if( rc == 0)
    {
        distrubute_mutex_unlock(m_mutex_key);
        LOG(INFO)<<"IdControlService-"<<__LINE__<<":SqlGetIdValue rc = " << rc;
        return 0;
    }
    uint32_t val = idInfo["value"].asUInt();
    uint32_t len = idInfo["len"].asUInt();

    if(SqlUpdateIdValue(m_id_type, len))
    {
        lPushRedisList(m_id_list_key, val + 1, len - 1);
        id = val;
    }
    distrubute_mutex_unlock(m_mutex_key);
    return id;

}

void IdControlService::lPushRedisList(const string& key, uint32_t start, uint32_t len)
{
    redisReply *reply;
    redisContext* ctx = glbRedis.getSt();
    
    for( uint32_t i = start; i < start + len ; ++i)
    {
        redisAppendCommand(ctx, "RPUSH %s %d", key.c_str(), i );
    }
    
    for( uint32_t j = start; j < start + len ; ++j)
    {
        if(redisGetReply(ctx, (void**)&reply) != REDIS_OK)
            LOG(INFO)<<" pipe error";
        freeReplyObject(reply);
    }    
    glbRedis.putSt(ctx);
}

long long int  IdControlService::getTimeMs()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ( (long long)tv.tv_sec*1000 + tv.tv_usec/1000 );
}