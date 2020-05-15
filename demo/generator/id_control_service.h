#ifndef _ID_CONTROL_SERVICE_H_
#define _ID_CONTROL_SERVICE_H_
#include<string>
#include <stdint.h>
#include "json.h"
using std::string;


class IdControlService{

private:
    IdControlService(const IdControlService & c);
    IdControlService& operator= (const IdControlService& a);
public: // business
    IdControlService(int id_type = 1);
    uint32_t getId();
    uint32_t pushIdList();
public:
    int distribute_mutex_lock(const string& mutex, int time_out = 3000); //锁的过期时间：毫秒
    int distrubute_mutex_unlock(const string& mutex);
    const string getMutexValue();
    long long int getTimeMs();
public: // redis
    void lPushRedisList(const string& key, uint32_t start, uint32_t len);
public: // sql
    int SqlGetIdValue(Json::Value& val, int id_type);
    bool SqlUpdateIdValue( int id_type, int len);


private:
    string m_mutex_key; //分布式锁
    string m_mutex_val; //锁的值
    string m_id_list_key;
    int m_id_type;

}; //IdControlService


#endif