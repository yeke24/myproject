#!/usr/bin/env python
# coding=utf8
#
from req import *
#import re

def test_banner_adinfo():
   url='http://xblapi.youban.com/operate/bannerbaginfo'
   data={"b":{"hd":1,"vender":"HUAWEI","brand":"HUAWEI","model":"HUAWEI CAZ-AL10"},"h":{"udid":"20275a6758a89fdb","deviceid":"864905033384848","uid":501,"ver":"8.6.8","device":1,"channel":"xbl_huawei"}}
   res=postreq(url,data)
   
   key='"res":"OK"'
   if key in res.text:
   	print ("url:bannerbaginfo is ok!")
   else:
   	print ("url:bannerbaginfo has error!")

   print(res.text);

if __name__ == "__main__":
   test_banner_adinfo()
