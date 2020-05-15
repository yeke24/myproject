#include<iostream>
#include<string>
#include "zktest.h"

uisng namespace std;

int main()
{
	sting host="192.168.10.99:2181,192.168.10.100:2181";
	string node ="/yeke/test/192.168.10.99:5168";
	string value ="yeke"
	int timeout=30000;

	ZkClient zk_c;

	zk_c.init(host,timeout);
	sleep(1);
	zk_c.regPathNode(node, value);
	sleep(1000);

	return 0;
}

/*int main(int argc, const char *argv[])
{
	const  char* host="192.168.10.99:2181,192.168.10.100:2181";
	int timeout=30000;

    zoo_set_debug_level(ZOO_LOG_LEVEL_WARN);

    zhandle_t* zkhandle;
    zkhandle= zookeeper_init(host, zktest_watcher_g, timeout, 0, 0, 0);

    if (zkhandle == NULL) {
        fprintf(stderr, "Error when connecting to zookeeper servers...\n");
        exit(EXIT_FAILURE);
    }

    int ret = zoo_acreate(zkhandle, "/xyz", "hello", 5,
           &ZOO_OPEN_ACL_UNSAFE, 0 , //ZOO_SEQUENCE
           zktest_string_completion, "acreate");
    if (ret) {
        fprintf(stderr, "Error %d for %s\n", ret, "acreate");
        exit(EXIT_FAILURE);
    }

    ret = 0;

    ret = zoo_aexists(zkhandle, "/xyz", 1, zktest_stat_completion, "aexists");
    if (ret) {
        fprintf(stderr, "Error %d for %s\n", ret, "aexists");
        exit(EXIT_FAILURE);
    }
    ret = 0;

    ret = zoo_adelete(zkhandle, "/xyz", -1, zktest_void_completion, "adelete");
    if (ret) {
        fprintf(stderr, "Error %d for %s\n", ret, "adelete");
        exit(EXIT_FAILURE);
    }
    getchar();

    zookeeper_close(zkhandle);

    return 0;
}*/