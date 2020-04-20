#!coding:utf-8

import sys
import requests
import json

def encode(str,key):
    data_json=str
    ml=len(data_json)
    kl=len(key)
    key=ml//kl*key+key[:ml%kl]
    

    pwd=[]
    for i in range(len(key)):
        pwd.append(chr(ord(key[i])^ord(data_json[i])))
    enstr=''.join(pwd)
    return enstr

def postreq(url,datasrc):
   data=json.dumps(datasrc)

   res=requests.post(url,data)

   return res

def encodepostreq(url,datasrc):
    data=json.dumps(datasrc)

    str=encode(data,'yBclOuD123')

    res=requests.post(url,str)
	
    return res   

def postreqform(url,datasrc):
   res=requests.post(url,datasrc)

   return res

def inform(info):
    url = "https://qyapi.weixin.qq.com/cgi-bin/webhook/send?key=75e49dab-3eb4-46e3-ab8f-60c40da1d468"
    headers = {"Content-Type": "text/plain"}
    s = info
    data = {"msgtype": "text","text": {"mentioned_list":["@all"],"content":s,}}
    r = requests.post(url, headers=headers, json=data)
    print(r.text)
   
def logformat(name, apiname, message):
    now = datetime.datetime.now()
    print('{0} {1} {2} {3}'.format(now, name, apiname, message))  
