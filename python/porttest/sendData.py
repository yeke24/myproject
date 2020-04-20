#!/usr/bin/env python
# coding=utf8
#
from req import *

def xuetangaddbill():
	data = {}
	data['uid'] = 501
	data['buid'] = hashlib.md5('%s_3rT0vA8BK8H#74Yr'%(data['uid'])).hexdigest()
	data['account'] = 0 
	data['btype'] = 0
	data['urltag'] = 0 
	data['bdata'] = 0
	data['udid'] = 0 
	data['deviceid'] = 0
	data['device'] = 0 
	data['version'] = 0
	data['ip'] = 0 
	data['buyway'] = 0
	data['promotion'] = 0 
	data['ssid'] = 0
	data['wid'] = 0 
	data['discount'] = 0
	data['rounding'] = 0 		
	req_sock('blxtaddbill', data)

def xbltvgetvideolist():
	data = {}
	data['uid'] = 501
	data['udid'] = 0 
	data['deviceid'] = 0
	data['device'] = 0 
	data['version'] = 0	
	#{"udid":"aaaaa111501","deviceid":"win501","uid":5210620,"version":"7.2.6","device":1}
	
	url='https://testxbltv.youban.com/gift/getvideolist'
	req_http(url, data)


def xbltvquitwatch():
	data = {}
	data['uid'] = 501
	data['udid'] = 0 
	data['deviceid'] = 0
	data['device'] = 0 
	data['version'] = 0	
	data['channelId']=1
	data['lessonId']=1111648
	data['vipstatus']=3
	data['startTime']=1526623500

	url='https://devxbltv.youban.com/xbltvapp/quitwatch'
	req_http(url, data)

def unbindphone():
	data = {}
	data['phone'] = '15820101664'
	data['skid'] = hashlib.md5('%s_uQWl65vSr@UYY8@b'%(data['phone'])).hexdigest()
	data['op'] = 0
	req_sock('bossunbindinfo', data)

def unbindweixin():
	data = {}
	data['uid'] = 22211331
	data['skid'] = hashlib.md5('%s_uQWl65vSr@UYY8@b'%(data['uid'])).hexdigest()
	data['op'] = 1
	req_sock('bossunbindinfo', data)

def GetV655erji():
	data = {}
	data['uid']=5037893
	data['device']=3
	data['hdtype']=1
	data['skid']=hashlib.md5('%s_asd123opqyb'%(data['uid'])).hexdigest()
	data['lasttime']=1504308818
	data['uptbean']=0
	data['version']='7.5.0'
	data['udid']='15647DB5-226C-4117-82EE-EB5BD85C10C7'
	data['debug']=0
	data['deviceid']='' 
	data['nowbean']=0
	req_sock('blv655geterjilist', data)

def userBagOp():
    data = {}
    data['op'] = 1
    data['uid'] = 501
    data['udid'] = '1115011'
    data['devid'] = '22211331'
    data['type'] = 5
    data['bag'] = 30
    data['info'] = "2@7385@2@1527764858@1529895596@0"
    req_sock('xbluserbagop', data)

def getClassDetailInfo()
	data = {}
    data['class_id'] = 0
    data['sub_class_id'] = 3
    data['skid'] = 'd0f102167a740f73e962f8e48d52240c'
    data['detail'] = 1
    req_sock('bossgetclassdetailinfo', data)

def getwxclassdetailinfo():
	data = {}
	data['sub_class_id'] = 10013
	data['skid'] = hashlib.md5('%d_uQWl65vSr@UYY8@b'%(data['sub_class_id'])).hexdigest()
	req_sock('boss_getwxclass_detailinfo', data)

def getaddressinfo():
	data = {}
    data['ip'] = ''
    data['uid'] = 501
    data['op'] = 1
    req_sock('commgetlocation', data)

def getuserareainfo():
	data = {}
    data['ip'] = ''
    data['uid'] = 501
    data['op'] = 1
    req_sock('baseuserareainfo', data)

def setuserareainfo():
	data = {}
    data['ip'] = '192.168.9.156'
    data['uid'] = 501
    data['op'] = 2
    data['city'] = '深圳'
    data['province'] = '广东'
    data['country'] = '中国'
    data['provider'] = '联通'
    req_sock('baseuserareainfo', data)        

if __name__ == "__main__":
	#queryVer()
	#reloadTpl()
	#queryAchieve()
	#BLXueTangAddBill()
	setuserareainfo()

