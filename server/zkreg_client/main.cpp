/*************************************************************************
*     > File Name: test.cpp
*     > Author: yeke
*     > Mail:yeke.com 
*     > Created Time:
*************************************************************************/

#include<iostream>
#include<string>
#include "zkclient_multireg.h"

using namespace std;

int main()
{
	string host="192.168.10.99:2181,192.168.10.100:2181";
	string node ="/yeke/test/192.168.10.99:5555";
	string value ="yeke";
	int timeout=10000;

	ZkClient zk_c;

//	zk_c.init(host,timeout);
//	sleep(1);
//	zk_c.regPathNode(node, value);

//	sleep(1000);
	if(!zk_c.init(host, timeout))
		return 0;
	zk_c.regPathNode(node, value);
	sleep(1000);

	return 0;
}