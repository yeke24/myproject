#!/usr/bin/env python
# encoding: utf-8

import os
import re
import datetime
import csv

headers=['时间段','下单数','下单成功数','下单失败数','回调数','支付成功数',' 支付失败数']

time=0
addbill_num=0
addbill_num_ok=0
addbill_num_fail=0

paybill_num=0
paybill_num_ok=0
paybill_num_fail=0

path = "/data/service/banlong/log"# 设置路径
dirs = os.listdir(path)                    			# 获取指定路径下的文件

for infile in dirs:                             	# 循环读取路径下的文件并筛选输出
    if os.path.splitext(infile)[1] == ".INFO":   	# 筛选banlong.INFO
        infile2="/data/service/banlong/log/"+infile
        file = open(infile2,"r")						
        for line in file.readlines():
            if line.find('recv:[blxtaddbill]')>=0:
                addbill_num+=1

            if line.find('resp:[blxtaddbill]')>=0:
                addbill_num_ok+=1
		
            if line.find('recv:[blxtrenewbill]')>=0:
                paybill_num+=1

            if line.find('resp:[blxtrenewbill]')>=0:
                paybill_num_ok+=1
        file.close()

    if re.search(r'banlong.*INFO',os.path.splitext(infile)[0]) is not None:  # 筛选banlong.*.INFO.*
        infile2="/data/service/banlong/log/"+infile
        file = open(infile2,"r")					
        for line in file.readlines():
            if line.find('recv:[blxtaddbill]')>=0:
                addbill_num+=1

            if line.find('resp:[blxtaddbill]')>=0:
                addbill_num_ok+=1
        
            if line.find('recv:[blxtrenewbill]')>=0:
                paybill_num+=1

            if line.find('resp:[blxtrenewbill]')>=0:
                paybill_num_ok+=1
        file.close()
rows=[('18:00-19:00', addbill_num, addbill_num_ok,addbill_num_fail,paybill_num,paybill_num_ok, paybill_num_fail)]
	
time = datetime.datetime.now()
ctime = str(time.year)+'-'+str(time.month)+'-'+str(time.day)

csv_file=open("xblxtbill"+ctime+".csv",'a+')
wf =csv.writer(csv_file)
wf.writerow(headers)
wf.writerows(rows)
csv_file.close()
