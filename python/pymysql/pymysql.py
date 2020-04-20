import pymysql
from sshtunnel import SSHTunnelForwarder
import csv
import time

#数据库地址
host={'99':{'IP':'127.0.0.1','user':'root','password':'gmptF*;hgKkG8rTKEm3c'},
      '100':{'IP':'192.168.10.100','user':'root','password':'gmptF*;hgKkG8rTKEm3c'},
      'RDS_DB':{'IP':'rm-wz94453yu525i62a5.mysql.rds.aliyuncs.com','user':'oper','password':'YB#fuhai209'}}



#用于建立ssh连接，实现端口数据转发，ssh到99，实现将本机的SQL操作由本机的57000转发到对应的数据库主句db_host
def ssh_and_transpond(db_host):
      print('正在建立SSH渠道，MYSQL连接到%s.......\n'%db_host)
      server =  SSHTunnelForwarder(ssh_address_or_host=('120.79.34.203',56000),ssh_username='root',ssh_password='fv!yh*POM5JJ*eQafoR#',
                                   local_bind_address=('127.0.0.1',57000),remote_bind_address=(db_host,3306))
      print('SSH连接建立完毕返回\n')
      return server

def init_db(user1,password1):
      print('初始化数据库............\n')
      db = pymysql.connect(host='127.0.0.1',port=57000,user=user1, passwd=password1 )
      cursor =db.cursor()
      print('数据库连接建立\n')
      return cursor,db

def timestamp_to_datetime(value):
    format = '%Y-%m-%d %H:%M:%S'
    value = time.localtime(value)
    dt = time.strftime(format, value)
    return dt