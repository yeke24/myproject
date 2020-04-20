#!/usr/bin/env python
# encoding: utf-8
import os
import re
import datetime
import csv

headers=['时间段','下单数','下单成功数','下单失败数','回调数','支付成功数',' 支付失败数']

time = datetime.datetime.now()
ctime1 = time.strftime("%Y%m%d")
ctime2 = time.strftime("%Y-%m-%d")
#time.strftime("%Y-%m-%d %H:%M:%S")
print(time)

addbill_num=0
addbill_num_ok=0
addbill_num_fail=0

paybill_num=0
paybill_num_ok=0
paybill_num_fail=0

path = "/data/service/banlong/log"# 设置路径
dirs = os.listdir(path)                             # 获取指定路径下的文件

for infile in dirs:                                 # 循环读取路径下的文件并筛选输出
    if os.path.splitext(infile)[1] == ".INFO":      # 筛选banlong.INFO
        print(infile)
        infile2="/data/service/banlong/log/"+infile
        file = open(infile2,"r")                        
        for line in file.readlines():
            if line.find('recv:[blxtaddbill]')>=0:
                addbill_num+=1

            if line.find('resp:[blxtaddbill]')>=0:
                if line.find('"res" : "OK"')>=0:
                    addbill_num_ok+=1
                else:
                    addbill_num_fail+=1
        
            if line.find('recv:[blxtrenewbill]')>=0:
                paybill_num+=1

            if line.find('resp:[blxtrenewbill]')>=0:
                if line.find('"res" : "OK"')>=0:
                    paybill_num_ok+=1
                else:
                    paybill_num_fail+=1
                    
        file.close()

    #file3='banlong.*.log.INFO.*'
    file3="banlong.*.log.INFO."+ctime1+"-*"
    if re.search(file3,os.path.splitext(infile)[0]) is not None:
    #if re.search(r'banlong.*.log.INFO.*',os.path.splitext(infile)[0]) is not None:  # 筛选banlong.*.INFO.*
    
        print(infile)
        infile2="/data/service/banlong/log/"+infile
        file = open(infile2,"r")                    
        for line in file.readlines():
            if line.find('recv:[blxtaddbill]')>=0:
                addbill_num+=1

            if line.find('resp:[blxtaddbill]')>=0:
                if line.find('"res" : "OK"')>=0:
                    addbill_num_ok+=1
                else:
                    addbill_num_fail+=1
        
            if line.find('recv:[blxtrenewbill]')>=0:
                paybill_num+=1

            if line.find('resp:[blxtrenewbill]')>=0:
                if line.find('"res" : "OK"')>=0:
                    paybill_num_ok+=1
                else:
                    paybill_num_fail+=1
        
        file.close()


rows=[(ctime2, addbill_num, addbill_num_ok,addbill_num_fail,paybill_num,paybill_num_ok, paybill_num_fail)]
    

csv_file=open("xblxtbill"+ctime2+".csv",'a+')
wf =csv.writer(csv_file)
wf.writerow(headers)
wf.writerows(rows)
csv_file.close()

print(datetime.datetime.now())