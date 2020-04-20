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
 

def get_ctime(result,cursor1):
      if int(result[1])>2000000:
            sql = 'select Faddtime from d_dhw.t_account_info where Fuid =' + str(result[1])
            cursor1.execute(sql)
            row =cursor1.fetchone()
            ctime=row[0]
      else:
            sql = 'select Fadd_time from d_hd_pad.t_uinfo where Fuid =' + str(result[1])
            cursor1.execute(sql)
            row = cursor1.fetchone()
            ctime=row[0]
      result.insert(2,timestamp_to_datetime(int(ctime)))
      

def bill_query(bill,cursor,no_exist):    #有错误返回空列表[]
      #结果result[订单，uid,开始时间，结束时间，支付渠道，支付金额]
      print("正在处理订单号：%s\n"%bill)
      channel= 'new'
      result=[]
      result.append(bill)                            #------------------------------
      sql = 'select Fuid,FproductName from d_dhw.t_bill_info where Fbill_id =' + "'" + bill + "'"
      cursor.execute(sql)
      row = cursor.fetchone()
      if(row):#订单在新的数据库中
            uid=row[0]
            #print(row)
            product= row[1]
            result.append(uid)                       #二二二二二二二二二二二二二二二
            sql='select * from d_dhw.t_member_info where Fuid='+str(uid)
            cursor.execute(sql)
            row = cursor.fetchone()
            if(row==None):
                  err = "订单:-%s-存在于d_dhw.t_bill_info，其uid为%s,但是不存在会员信息,用户购买的商品为:%s："%(bill,uid,product)
                  #print(err)
                  no_exist.append(err)
                  return []
            begin_time=row[7]   #会员开始时间
            end_time=row[4]   #会员结束时间
            if begin_time=='0':
                  sql='select Fbegin_time from d_hd_pad.t_uinfo where Fuid='+str(uid)
                  cursor.execute(sql)
                  row = cursor.fetchone()
                  begin_time=row[0]
            result.append(begin_time)               #三三三三三三三三三三三三三三三三
            result.append(end_time)                  #四四四四四四四四四四四四四四四四四
            get_ctime(result,cursor)
            return result

      else:     

            #订单在旧的数据库中
            sql = 'select Fuid from d_hd_pad.t_hd_xuetang_bill where Fbill_id =' + "'" + bill + "'"
            cursor.execute(sql)
            row = cursor.fetchone()
            if(row):
                  uid=row[0]
                  #print(uid)
                  result.append(uid)                   #二二二二二二二二二二二二二二二
                  sql='select Fbegin_time,Fend_time from d_hd_pad.t_uinfo where Fuid='+str(uid)
                  cursor.execute(sql)
                  row = cursor.fetchone()
                  if(row==None):
                        err= "订单:-%s-存在于数据库表d_hd_pad.t_hd_xuetang_bill，其uid为%s,但是不存在会员信息"%(bill,uid)
                        #print(err)
                        no_exist.append(err)
                        return []
                  begin_time=row[0]   #会员开始时间
                  end_time=row[1]     #会员结束时间
                  #if begin_time=='0':
                  #      sql='select Fbegin_time from d_dhw.t_member_info where Fuid='+str(uid)
                  #      cursor.execute(sql)
                  #      row = cursor.fetchone()
                  #      begin_time=row[0]
                  result.append(begin_time)               #三三三三三三三三三三三三三三三三
                  result.append(end_time)                  #四四四四四四四四四四四四四四四四四
                  get_ctime(result,cursor)
                  return result
            else:
                  return []
            
            
      

#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++SQL_QUERY0++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
def sql_query(db_cursor):
      print('开始数据库查询\n')
      invalid_bill=[]
      #下面写将要进行的操作
      with open('export_in.csv','r',encoding='gbk') as in_data ,open('export_out.csv','w',newline='') as out_data:
            readers = csv.reader(in_data)
            writers=csv.writer(out_data)
            title=['订单号','uid','用户注册时间','会员开始时间','会员结束时间','支付渠道','支付金额']
            writers.writerow(title)
            a=0
            b=0
            for line in readers:
                  a=a+1
                  if a<=5:
                        continue
                  b=b+1
                  print('正在处理第%d个订单\n'%b)
                  bill_id = line[2].strip("`") #订单号
                  result = bill_query(bill_id,db_cursor,invalid_bill)
                  #[订单，uid,开始时间，结束时间，支付渠道，支付金额]
                  if(len(result)==0):     #列表为空代表没有返回结果
                        continue
                  result[3]=timestamp_to_datetime(int(result[3]))
                  result[4]=timestamp_to_datetime(int(result[4]))
                  result.append(line[3])
                  result.append(line[5])
                  print(result)
                  print('\n')
                  writers.writerow(result)
            for noexist in invalid_bill:
                  print(noexist)

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++SQL_QUERY1++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
def write_file(buy_info):
       with open('export_member_info.csv','w',newline='') as member ,open('export_trade_info.csv','w',newline='') as trade:
             title_member=['UID','手机号','用户注册时间','会员开始时间','会员结束时间']
             title_trade=['UID','手机号','微信号','用户注册时间','订单号','支付金额','购买商品名称','购买渠道','会员开始时间','会员结束时间','下单时间']
             mem_write=csv.writer(member)
             tra_write=csv.writer(trade)
             mem_write.writerow(title_member)
             tra_write.writerow(title_trade)
             for uid in buy_info:
                  if buy_info[uid]['end_time']=='':
                        continue
                  
                  phone=buy_info[uid]['phone']
                  addtime=timestamp_to_datetime(int(buy_info[uid]['addtime']))
                  begintime=timestamp_to_datetime(int(buy_info[uid]['begin_time']))
                  endtime=timestamp_to_datetime(int(buy_info[uid]['end_time']))

                  w=[]
                  w.append(uid)
                  w.append(phone)
                  w.append(addtime)
                  w.append(begintime)
                  w.append(endtime)
                  mem_write.writerow(w)
                  
             for uid in buy_info:
                  if len(buy_info[uid]['order'])==0:
                        continue
                  phone=buy_info[uid]['phone']
                  unionid=buy_info[uid]['unionid']
                  addtime=timestamp_to_datetime(int(buy_info[uid]['addtime']))
                  if(buy_info[uid]['end_time']==''):
                        begintime=0
                        endtime=0
                  else:
                        begintime=timestamp_to_datetime(int(buy_info[uid]['begin_time']))
                        endtime=timestamp_to_datetime(int(buy_info[uid]['end_time']))
                  bill_sets=buy_info[uid]['order']
                  for bill in bill_sets:
                        w=[]
                        w.append(uid)
                        w.append(phone)
                        w.append(unionid)
                        w.append(addtime)
                        w.append(bill[1])
                        w.append(int(bill[2])/100)
                        w.append(bill[4])
                        w.append(bill[5])
                        w.append(begintime)
                        w.append(endtime)
                        w.append(timestamp_to_datetime(int(bill[6])))
                        tra_write.writerow(w)
                        
                  
                  
                  


def sql_query1(cursor):              #根据查询所有手机用户的消费信息
      
      sql_new="select Fuid,Fbill_id,Famount,Fgoods,FproductName,Fchannel,ForderTime from d_dhw.t_bill_info where Fbuystatus=1 and Fuid in (select Fuid from d_dhw.t_account_info where Faddtime>1517414400) "
      sql_old="select Fuid,Fbill_id,Famount,Fgoods,FproductName,Fchannel,ForderTime from d_hd_pad.t_hd_xuetang_bill where Fbuystatus=1 and Fuid in (select Fuid from d_hd_pad.t_uinfo where Fadd_time>1517414400) "
      cursor.execute(sql_new)
      rows_new = cursor.fetchall()
      print("\n\n新版订单数量：%d\n\n"%len(rows_new))
      cursor.execute(sql_old)
      rows_old = cursor.fetchall()
      print("\n\n旧的订单数量：%d\n\n"%len(rows_old))
      rows=rows_new + rows_old #获取所有订单信息
      print("\n\n\n总的订单数量为：%d\n\n\n"%len(rows))
      uid_set=set()            
      for row in rows:
            uid_set.add(row[0])#获取订单中所有uid
      print('在3月2号以后办理业务的uid如下\n\n\n')
      print(uid_set)
      print('\n\n在3月2号以后办理业务的总的uid数量为%d\n\n\n'%len(uid_set))
      buy_info=[]
      user_buy_info={}     #用户购买记录
      countt=0
      for uid1 in uid_set:
            #uid，手机 注册时间 账单 金额 商品名称 购买渠道
            sql = 'select Fphone,Faddtime,Funionid from d_dhw.t_account_info where Fuid='+str(uid1)
            cursor.execute(sql)
            row = cursor.fetchone()
            info=[]
            info.append(uid1)#uid
            phone = row[0]    #手机
            addtime = row[1]  #注册时间
            unionid=row[2]
            order_set=[]      #[(),(),(),(),()]
            for suborder in rows:
                  if (suborder[0]==uid1):
                        order_set.append(suborder)
            #print(order_set)
            sql ='select * from d_dhw.t_member_info where Fuid='+str(uid1)
            #print(sql)
            cursor.execute(sql)
            row = cursor.fetchone()
            #print(row)
            if(row):
                  begin_time=row[7]
                  end_time=row[4]
            else:
                  begin_time=''
                  end_time=''
            
            this_uid_info={}
            this_uid_info["phone"]=phone
            this_uid_info["unionid"]=unionid
            this_uid_info['addtime']=addtime
            this_uid_info['begin_time']=begin_time
            this_uid_info['end_time']=end_time
            this_uid_info['order']=order_set
            sql='%s'%uid1
            user_buy_info[sql]=this_uid_info
            countt=countt+1
            print('%d\n'%countt)
            print(this_uid_info)
            print('\n\n\n')
      write_file(user_buy_info)
      #return user_buy_info
            
            
            
            
      #rownums = cursor.rowcount
      #sql = 'select Fuid Fendtime'
      #print(cursor.fetchall())
      """for i in range(rownums):
            row =cursor.fetchone()
            uid=row[0]
            phone=row[1]
            addtime=row[2]"""








#======================================================================SQL_QUEERY2=================================================================
def write_file1(buy_info):
       with open('export_hwid_trade_info.csv','w',newline='') as trade:
             title_trade=['HWID','UID','手机号','用户注册时间','订单号','支付金额','购买商品名称','购买渠道','会员开始时间','会员结束时间','下单时间']
             tra_write=csv.writer(trade)
             tra_write.writerow(title_trade)
                  
             for hwid in buy_info:
                  if len(buy_info[hwid]['order'])==0:
                        continue
                  phone=buy_info[hwid]['phone']
                  uid=buy_info[hwid]['uid']
                  addtime=timestamp_to_datetime(int(buy_info[hwid]['addtime']))
                  if(buy_info[hwid]['end_time']==''):
                        begintime=0
                        endtime=0
                  else:
                        begintime=timestamp_to_datetime(int(buy_info[hwid]['begin_time']))
                        endtime=timestamp_to_datetime(int(buy_info[hwid]['end_time']))
                  bill_sets=buy_info[hwid]['order']
                  for bill in bill_sets:
                        w=[]
                        w.append(hwid)
                        w.append(uid)
                        w.append(phone)
                        w.append(addtime)
                        w.append(bill[1])
                        w.append(int(bill[2])/100)
                        w.append(bill[4])
                        w.append(bill[5])
                        w.append(begintime)
                        w.append(endtime)
                        w.append(timestamp_to_datetime(int(bill[6])))
                        tra_write.writerow(w)
                        
                  


def sql_query2(cursor):
      sql_old="select Fhwid,Fbill_id,Famount,Fgoods,FproductName,Fchannel,ForderTime from d_hd_pad.t_hd_xuetang_bill where Fbuystatus=1 and Fhwid!='' "
      cursor.execute(sql_old)
      rows = cursor.fetchall()
      print("\n\n旧的hwid的订单数量：%d\n\n"%len(rows))
      hwid_set=set()            
      for row in rows:
            hwid_set.add(row[0])#获取订单中所有uid
      print('在3月2号以后办理业务的hwid如下\n\n\n')
      print(hwid_set)
      print('\n\n在3月2号以后办理业务的总的hwid数量为%d\n\n\n'%len(hwid_set))
      buy_info=[]
      user_buy_info={}     #用户购买记录
      countt=0
      for hwid in hwid_set:
            #uid，手机 注册时间 账单 金额 商品名称 购买渠道
            sql = 'select Fphone,Fadd_time,Fuid from d_hd_pad.t_uinfo where Fhwid='+"'"+hwid+"'"
            #print(sql)
            cursor.execute(sql)
            row = cursor.fetchone()
            if(row==None):
                  continue
            info=[]
            info.append(hwid)#hwid
            phone = row[0]    #手机
            addtime = row[1]  #注册时间
            uid=row[2]
            order_set=[]      #[(),(),(),(),()]
            for suborder in rows:
                  if (suborder[0]==hwid):
                        order_set.append(suborder)
            #print(order_set)
            sql ='select * from d_dhw.t_member_info where Fuid='+str(uid)
            #print(str(uid)+"=====")
            #print(sql)
            cursor.execute(sql)
            row = cursor.fetchone()
            #print(row)
            #print(row)
            if(row):
                  begin_time=row[7]
                  end_time=row[4]
            else:
                  begin_time=''
                  end_time=''
            
            this_uid_info={}
            this_uid_info["uid"]=uid
            this_uid_info["phone"]=phone
            this_uid_info['addtime']=addtime
            this_uid_info['begin_time']=begin_time
            this_uid_info['end_time']=end_time
            this_uid_info['order']=order_set
            sql='%s'%hwid
            user_buy_info[sql]=this_uid_info
            countt=countt+1
            print('%d\n'%countt)
            print(this_uid_info)
            print('\n\n\n')
            #print("==========")
      #print(user_buy_info)
      write_file1(user_buy_info)

      
#======================================================================MAIN=======================================================================
#ssh属性设置
def main(db_addr):
      print('程序进入:\n')
      server = ssh_and_transpond(db_addr['IP'])
      #开启ssh渠道
      server.start()
      #数据初始化
      cursor,db = init_db(db_addr['user'],db_addr['password'])

      #____________________________________________________在下面执行sql函数

      #SQL查询
      #sql_query(cursor)             #根用户订单信息查询用户的购买数据，需要输入csv格式的订单信息
      #sql_query1(cursor)              #1. 根据订单查询所有手机用户和微信用户的消费信息
      #sql_query2(cursor)              #2. 查询老版通过hwid购买的购买记录
      sql_query3(cursor)              #3. 

      #____________________________________________________在上面执行sql函数
      #关闭ssh渠道和mysql
      db.close()
      server.stop()


  
#if (__name__=='__nain__'):
#      print('aaaaaaaaaaaaaaaa')    
main(host['RDS_DB'])
