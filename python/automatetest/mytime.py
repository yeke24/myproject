#!/usr/bin/python
# -*- coding: UTF-8 -*-

import time
import requests

def myinform(info):
    url = "https://qyapi.weixin.qq.com/cgi-bin/webhook/send?key=f22dcb4c-bc13-46d4-bc2a-a5ff567bbd81"
    headers = {"Content-Type": "text/plain"}
    s = info
    data = {"msgtype": "text","text": {"mentioned_list":["@all"],"content":s,}}
    r = requests.post(url, headers=headers, json=data)
    print(r.text)

from datetime import datetime
dt=datetime.now()
print dt.year,dt.month,dt.day,dt.hour,dt.minute,dt.second,dt.month

while(1):
	dt=datetime.now()
	if(dt.hour==10 && dt.second==0):
		#print "yeke"
		myinform("walter is stupid")
		time.sleep(1)
	

