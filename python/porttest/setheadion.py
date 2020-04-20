#!/usr/bin/env python
# coding=utf8
#
from req import *

import csv
import re
import os

def xbl_set_headicon(uid):
        data={}
        data['headimg']='20200226/5e5620aba64a4.png'
        data['op']=3
        data['uid']=uid
        data['app']=0
        req_sock('commuseruinfo', data)

if __name__ == "__main__":
        with open('weigui.csv')as f:
    		f_csv = csv.reader(f)
		for row in f_csv:
			#print(row[0])
			xbl_set_headicon(row[0])
