#!/usr/bin/env python
# encoding: utf-8
import os
import re
import datetime
import time
import csv

time=('00-01','01-02','02-03','03-04','04-05','05-06','06-07','07-08','08-09','09-10','10-11','11-12',
	'12-13','13-14','14-15','15-16','16-17','17-18','18-19','19-20','20-21','21-22','22-23','23-24')
addbill_num=[0,]*24 
addbill_num_ok=[0,]*24
addbill_num_fail=[0,]*24

paybill_num=[0,]*24
paybill_num_ok=[0,]*24
paybill_num_fail=[0,]*24

start_time=datetime.datetime.now()
ctime1=start_time.strftime("%Y%m%d")
ctime2=start_time.strftime("%Y-%m-%d")
#time.strftime("%Y-%m-%d %H:%M:%S")
print(start_time)

path = "/data/service/banlong/log"# 设置路径
dirs = os.listdir(path)                             # 获取指定路径下的文件

for infile in dirs:                                 # 循环读取路径下的文件并筛选输出

    file3="banlong.*.log.INFO."+ctime1+"-*"		# 筛选banlong.*.log.INFO.‘ctime1’-*
    if re.search(file3,os.path.splitext(infile)[0]) is not None:    
        print(infile)
        infile2="/data/service/banlong/log/"+infile
        file = open(infile2,"r")                    
        for line in file.readlines():
            if line.find('recv:[blxtaddbill]')>=0:		#下单数
                hour_num=int(line[6:8])
                addbill_num[hour_num]+=1

            if line.find('resp:[blxtaddbill]')>=0:
                if line.find('"res" : "OK"')>=0:
                    hour_num=int(line[6:8])
                    addbill_num_ok[hour_num]+=1
                else:
                    addbill_num_fail[hour_num]+=1
                    print(line)
        
            if line.find('recv:[blxtrenewbill]')>=0:
                hour_num=int(line[6:8])
                paybill_num[hour_num]+=1

            if line.find('resp:[blxtrenewbill]')>=0:
                if line.find('"res" : "OK"')>=0:
                    hour_num=int(line[6:8])
                    paybill_num_ok[hour_num]+=1
                else:
                    paybill_num_fail[hour_num]+=1
                    print(line)
                    
        file.close()

    if os.path.splitext(infile)[1] == ".INFO":      # 筛选banlong.INFO
        print(infile)
        infile2="/data/service/banlong/log/"+infile
        file = open(infile2,"r")                        
        for line in file.readlines():
            if line.find('recv:[blxtaddbill]')>=0:		#下单数
                hour_num=int(line[6:8])
                addbill_num[hour_num]+=1

            if line.find('resp:[blxtaddbill]')>=0:
                if line.find('"res" : "OK"')>=0:
                    hour_num=int(line[6:8])
                    addbill_num_ok[hour_num]+=1
                else:
                    addbill_num_fail[hour_num]+=1
                    print(line)
        
            if line.find('recv:[blxtrenewbill]')>=0:
                hour_num=int(line[6:8])
                paybill_num[hour_num]+=1

            if line.find('resp:[blxtrenewbill]')>=0:
                if line.find('"res" : "OK"')>=0:
                    hour_num=int(line[6:8])
                    paybill_num_ok[hour_num]+=1
                else:
                    paybill_num_fail[hour_num]+=1
                    print(line)

        file.close()

headers=['时间段','下单数','下单成功数','下单失败数','回调数','支付成功数',' 支付失败数']
rows = []          ## 空列表

for hour in range(0,24):
    tup=()
    tup=(time[hour], addbill_num[hour], addbill_num_ok[hour],addbill_num_fail[hour],paybill_num[hour],paybill_num_ok[hour], paybill_num_fail[hour])
    print(tup)
    rows.append(tup)   ## 使用 append() 添加元素

csv_file=open("xblxtbill"+ctime2+".csv",'a+')
wf =csv.writer(csv_file)
wf.writerow(headers)
wf.writerows(rows)
csv_file.close()

end_time=datetime.datetime.now()
print(end_time)