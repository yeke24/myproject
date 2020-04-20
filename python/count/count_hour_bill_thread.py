#!/usr/bin/env python
# encoding: utf-8
import os
import re
import datetime
import time
import csv
import threading

daytime=('00~01','01~02','02~03','03~04','04~05','05~06','06~07','07~08','08~09','09~10','10~11','11~12',
    '12~13','13~14','14~15','15~16','16~17','17~18','18~19','19~20','20~21','21~22','22~23','23~24')
addbill_num=[0,]*25 
addbill_num_ok=[0,]*25
addbill_num_fail=[0,]*25

paybill_num=[0,]*25
paybill_num_ok=[0,]*25
paybill_num_fail=[0,]*25

lock=threading.Lock()

start_time=datetime.datetime.now()
ctime1=start_time.strftime("%Y%m%d")
ctime2=start_time.strftime("%Y-%m-%d")
#time.strftime("%Y-%m-%d %H:%M:%S")
print(start_time)


def count(infile):  
    infile2="/data/service/banlong/log/"+infile
    #infile2="/home/yeke/python/"+infile
    file = open(infile2,"r")                    
    for line in file.readlines():
        if line.find('recv:[blxtaddbill]')>=0:      #下单数
            hour_num=int(line[6:8])
            global addbill_num
            with lock:
                addbill_num[hour_num]+=1

        if line.find('resp:[blxtaddbill]')>=0:
            hour_num=int(line[6:8])
            if line.find('"res" : "ERR"')>=0:
                global addbill_num_fail
                with lock:
                    addbill_num_fail[hour_num]+=1
                print(line)                         #打印失败的信息
            else:
                global addbill_num_ok
                with lock:
                    addbill_num_ok[hour_num]+=1
    
        if line.find('recv:[blxtrenewbill]')>=0:
            hour_num=int(line[6:8])
            global paybill_num
            with lock:
                paybill_num[hour_num]+=1

        if line.find('resp:[blxtrenewbill]')>=0:
            hour_num=int(line[6:8])
            if line.find('"res" : "OK"')>=0:
                global paybill_num_ok
                with lock:
                    paybill_num_ok[hour_num]+=1
            else:
                global paybill_num_fail
                with lock:
                    paybill_num_fail[hour_num]+=1
                print(line)
    file.close()

def csv():
    headers=['时间段','下单数','下单成功数','下单失败数','回调数','支付成功数',' 支付失败数']
    rows = []

    start_time=datetime.datetime.now()
    ctime2=start_time.strftime("%Y-%m-%d")        

    for hour in range(0,24):
        tup=()
        tup=(daytime[hour], addbill_num[hour], addbill_num_ok[hour],addbill_num_fail[hour],
            paybill_num[hour],paybill_num_ok[hour], paybill_num_fail[hour])
        print(tup)
        rows.append(tup)   ## 添加时间段统计数据 0-23小时

        addbill_num[24]+=addbill_num[hour]
        addbill_num_ok[24]+=addbill_num_ok[hour]
        addbill_num_fail[24]+=addbill_num_fail[hour]
        paybill_num[24]+=paybill_num[hour]
        paybill_num_ok[24]+=paybill_num_ok[hour]
        paybill_num_fail[24]+=paybill_num_fail[hour]

    tup=() 
    tup=(ctime2, addbill_num[24], addbill_num_ok[24],addbill_num_fail[24],
        paybill_num[24],paybill_num_ok[24], paybill_num_fail[24])    #一天的总数据
    print(tup)
    rows.append(tup)

    csv_file=open("xblxtbill"+ctime2+".csv",'a+') #文件名包含日期
    csv_file.write('\xEF\xBB\xBF')      #解决中文编码
    wf =csv.writer(csv_file)
    wf.writerow(headers)
    wf.writerows(rows)
    csv_file.close()


if __name__=='__main__':
    path = "/data/service/banlong/log"# 设置路径
    #path ="/home/yeke/python"
    dirs = os.listdir(path)                             # 获取指定路径下的文件
    start_time=datetime.datetime.now()
    ctime1=start_time.strftime("%Y%m%d")
    print(start_time)

    for infile in dirs:                                 # 循环读取路径下的文件并筛选输出
        find_file="banlong.*.log.INFO."+ctime1+"-*"     # 筛选banlong.*.log.INFO.‘ctime1’-*
        if re.search(find_file,os.path.splitext(infile)[0]) is not None:
            print(infile)
            my_thread=threading.Thread(target=count,args=(infile,))  #开线程统计
            my_thread.setDaemon(False)
            my_thread.start()

    csv()
    end_time=datetime.datetime.now()
    print(end_time)
