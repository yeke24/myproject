#!/usr/bin/env python
# coding=utf8
#
from req import *
import json

def test_banner_adinfo():
   url='http://xblapi.youban.com/operate/bannerbaginfo'
   data={"b":{"hd":1,"vender":"HUAWEI","brand":"HUAWEI","model":"HUAWEI CAZ-AL10"},"h":{"udid":"20275a6758a89fdb","deviceid":"864905033384848","uid":501,"ver":"8.6.7","device":1,"channel":"xbl_huawei"}}
   res=postreq(url,data)
   #print(res.text);

   key='"res":"OK"'
   if key in res.text:
        print ("url:bannerbaginfo is ok!")
   else:
        print ("url:bannerbaginfo has error!")
        inform("url:bannerbaginfo has error!")

def test_insert_adinfo():
    url='http://xblapi.youban.com/operate/insertadinfo'
    data={"b":{"hd":1,"vender":"HUAWEI","brand":"HUAWEI","model":"HUAWEI CAZ-AL10"},"h":{"udid":"20275a6758a89fdb","deviceid":"864905033384848","uid":501,"ver":"8.7.4","device":1,"channel":"xbl_huawei"}}
    res=postreq(url,data)
    key='"res":"OK"'
    if key in res.text:
         print ("url:insertadinfo is ok!")
    else:
         print ("url:insertadinfo has error!")
         inform("url:insertadinfo has error!")

def test_inspire_adinfo():
   url='https://xblapi.youban.com/operate/inspireadinfo'
   data={"b":{"hd":1},"h":{"udid":"3d30a520348eae9a","deviceid":"864692031669616","uid":228,"ver":"8.7.0","device":1,"channel":"xbl_360"}}
   res=postreq(url,data)
   #print(res.text);
   key='"res":"OK"'
   if key in res.text:
        print ("url:inspireadinfo is ok!")
   else:
        print ("url:inspireadinfo has error!")
        inform("url:inspireadinfo has error!")

def test_getxblhomescence_info():
   url='https://xblapi.youban.com/xblbase/getxblhomescence.php'
   data={"n":{"channel":"xbl_oppo"},"h":["842aa857eefd8399","A0000085E5E7BF",226982171111,"8.7.2",1,1571387799]}
   res=encodepostreq(url,data)
   #print(res)
   #print(res.text)
   key='"res":"OK"'
   if key in res.text:
        print ("url:getxblhomescence.php is ok!")
   else:
        print ("url:getxblhomescence.php has error!") 
        inform("url:getxblhomescence.php has error!")
        #print(res.text)
    
def test_ad_detail():
   url='https://xblcommon.youban.com/ad/detail'
   data={"b":{"site":1002,"app":0},"h":{"udid":"3d30a520348eae9a","deviceid":"864692031669616","uid":228,"ver":"8.7","device":1,"channel":"xbl_360"}}
   res=postreq(url,data)
   #print(res.text)
   key ='"rc":0'
   if key in res.text:
        print ("url:ad/detail is ok!")
   else:
        print ("url:ad/detail has error!")
        inform("url:ad/detail has error!")	

def test_655erji_detail():
   url='https://xblapi.youban.com/phonexbl/getV655erji.php'
   data={'device':(None,'1'),'hdtype':(None,'1'),'deviceid':(None,'866258030662941'),'app':(None,'0'),'skid':(None,'5d1e141da12ccc053e4168410a6ad2f7'),'version':(None,'8.3.0'),'uid':(None,'39025031'),'udid':(None,'897d811bf97e0c66')}
   res = postreqform(url,data)
   key='"res":"OK"'
   if key in res.text:
        print ("url:getV655erji.php is ok!")
   else:
        print ("url:getV655erji.php has error!") 
        inform("url:getV655erji.php has error!")

def test_tplsource_info():
   url='https://xblapi.youban.com/config/query-tpl-source'
   data={"h": {"device": 0, "ver": "8.4.0", "uid": 1}, "b": {"keys": "yuyin"}}
   res = postreq(url,data)
   key ='"rc":0'
   if key in res.text:
        print ("url:query-tpl-source is ok!")
   else:
        print ("url:query-tpl-source has error!")
        inform("url:query-tpl-source has error!") 
 
if __name__ == "__main__":
   test_banner_adinfo()   
   test_insert_adinfo()
   test_inspire_adinfo()
   test_getxblhomescence_info()
   test_ad_detail()
   test_655erji_detail()
   test_tplsource_info()

