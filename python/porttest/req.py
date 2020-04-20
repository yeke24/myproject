#!/usr/bin/env python
# coding=utf8
#
import socket
import time
import json
import hashlib
from util_pycurl import connector

g_version = 1.0
g_gid = 0
g_uid = 0

host = "192.168.10.99"
port = 8876

def req_sock(cmd, dat):
	if not isinstance(dat, dict):
		print 'dict require!'
		return
	dat = json.dumps(dat, ensure_ascii=False)
	sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	hostport = (host, port)
	data = 'Version:%s\r\nLength:%d\r\nCommand:%s\r\nUid:%d\r\nGid:%d\r\n\r\n%s'%(g_version
			, len(dat)
			, cmd
			, g_uid
			, g_gid
			, dat)
	sock.connect(hostport)
	print 'send:[%s]'%(data)
	sock.send(data)
	recvdata = ''
	while True:
		batch = sock.recv(256)
		if not batch:
			break
		#print 'recv %s'%(len(batch))
		recvdata += batch
	print 'recv:[%s], len:[%s]'%(recvdata, len(recvdata))

def req_http(url, dat):
	connector.set_header(['content-type: application/json'])
	if connector.post(url, json.dumps(dat)):
		print 'recv http:[%s]'%(connector.get_content())
	else:
		print 'req http failed'
