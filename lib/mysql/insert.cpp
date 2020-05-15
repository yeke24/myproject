#include <iostream>
#include <mysql/mysql.h>
#include <string>
using namespace std;
main()
{
     MYSQL mysql;
     mysql_init(&mysql);
     mysql_real_connect(&mysql, "localhost", "root", "Mysql123.", "yeke", 3306, NULL, 0);
     //string sql = "insert into t_account_info_yeke_partition set Fuid=1,Fphone=11145678910;";
     string sql = "update t_account_info_yeke_partition set Fphone=11145678910 where Fuid=50;";

     mysql_query(&mysql, sql.c_str());
     mysql_close(&mysql);
}
