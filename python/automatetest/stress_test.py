#!/usr/bin/env python
# coding=utf8
#
from req import *
import re;
import json
import threading
from time import ctime,sleep
import datetime

def test_post(n):
   url='https://testxblapi.youban.com/config/commoncfg'
   data={"h": {"device": 0, "ver": "8.7.5", "uid": 1}, "b": {"channel": "xbl_huawei"}}
   res=postreq(url,data)

   key ='"rc":0'
   #if key in res.text:
      #print ('压力测试 线程'+str(n)+':'+ 'url:config/commoncfg is ok!')
   #else:
   rc=re.search(key,res.text)
   if not rc:
      print ('压力测试 线程'+str(n)+':'+ 'url:config/commoncfg has error!')
      myinform('压力测试 线程'+str(n)+':'+ 'url:'+url+' has error!')
   #sleep(1)

def thread(name,n):
   threads = []
   for i in range(0,n):
      t=threading.Thread(target=name, args=(i,))
      threads.append(t)

   starttime = datetime.datetime.now()
   print('starttime:'+str(starttime))
   for t in threads:
      t.start()
   for t in threads:
      t.join()
   endtime = datetime.datetime.now()
   print('endtime:'+str(endtime))

if __name__ == "__main__":
   thread(test_post,1000)
