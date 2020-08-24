#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <string.h>
extern int errno;

#define BUFFSIZE 1024

int main(int argc, char const *argv[])
{
    int clifd;
    struct sockaddr_in cliaddr_in;
    char sendBuf[1024], recvBuf[1024];

    if((clifd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        fprintf(stderr, "创建套接字失败,%s\n", strerror(errno));
        exit(errno);
    }

    if(argc !=3)
        printf("usage: tcpcli <IPaddress> and Port!");

    //char ip[256] = {0};
    //snprintf(ip,sizeof(ip),"%s",argv[1]);

    //cliaddr_in.sin_family = AF_INET;
    //cliaddr_in.sin_addr.s_addr = inet_addr(ip);
    //cliaddr_in.sin_port = htons(argv[2]);

    bzero(&cliaddr_in, sizeof(cliaddr_in));
    cliaddr_in.sin_family=AF_INET;
    //cliaddr_in.sin_port=htons(110);
    Inet_pton(AF_INET,argv[1],&cliaddr_in.sin_addr);
    cliaddr_in.sin_port=htons(argv[2]);

    if(connect(clifd, (struct sockaddr *)&cliaddr_in, sizeof(struct sockaddr)) == -1){
        fprintf(stderr,"请求连接服务器失败, %s\n", strerror(errno));
        exit(errno);
    }

    gets(sendBuf);

    printf("######## send:\n%s\n\n",sendBuf);
    if(send(clifd, sendBuf, strlen(sendBuf), 0) == -1){
        fprintf(stderr, "send message error:(, %s\n", strerror(errno));
        exit(errno);
    }

   int  len = recv(clifd, recvBuf, BUFFSIZE, 0);
   printf("######## %d received:\n%s\n",len, recvBuf);

    close(clifd);
    return 0;
}

//scanf();//不能有空格 \r \n;
//strcpy(sendBuf,"Version:1.0\r\nLength:28\r\n Command:bossflushallmemcached\r\nUid:0\r\nGid:0\r\n\r\n{\"env\": \"dev\",\"name\":\"yeke\"}");
//strcpy(sendBuf,"FD:12\r\nVersion:1.0\r\nLength:28\r\n Command:bossflushallmemcached\r\nUid:0\r\nGid:0\r\n\r\n{\"env\": \"dev\",\"name\":\"keke\"}");
//9924//strcpy(sendBuf,"FD:12\r\nVersion:1.0\r\nLength:100\r\n Command:bossflushallmemcached\r\nUid:0\r\nGid:0\r\n\r\n{\"env\": \"dev\"}Version:1.0\r\nLength:14\r\n Command:bossflushallmemcached\r\nUid:0\r\nGid:0\r\n\r\n{\"env\": \"dev\"}");
//9981//strcpy(sendBuf,"FD:13\r\nVersion:1.0\r\nLength:102\r\nCommand:baseuserinfo\r\nUid:0\r\nGid:0\r\n\r\n{\"udid\":\"aa321eea38e0b4d6\",\"deviceid\":\"864176033540264\",\"uid\":3000501,\"ver\":\"8.8.6\",\"device\":1,\"op\":2}");