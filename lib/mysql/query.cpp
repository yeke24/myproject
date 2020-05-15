#include <iostream>
#include <string>
#include <mysql/mysql.h>

using namespace std;

main()
{
    MYSQL mysql;
    MYSQL_RES *result = NULL;
    MYSQL_FIELD *field = NULL;
    mysql_init(&mysql);
    mysql_real_connect(&mysql, "localhost", "root","Mysql123.", "yeke", 3306, NULL, 0);
    string str = "select Fuid , Fphone from  t_account_info_yeke_partition;";
    mysql_query(&mysql, str.c_str());
    result = mysql_store_result(&mysql);
    int rowcount = mysql_num_rows(result);
    cout << rowcount << endl;
    int fieldcount = mysql_num_fields(result);
    cout << fieldcount << endl;
    for(int i = 0; i < fieldcount; i++)
    {
     field = mysql_fetch_field_direct(result,i);
     cout << field->name << "\t\t";
    }
    cout << endl;
    MYSQL_ROW row = NULL;
    row = mysql_fetch_row(result);
    while(NULL != row)
    {
     for(int i=0; i<fieldcount; i++)
     {
        cout << row[i] << "\t\t";
     }
     cout << endl;
     row = mysql_fetch_row(result);
    }
    mysql_close(&mysql);
}
