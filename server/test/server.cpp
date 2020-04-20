#include <sys/types.h>  
#include <sys/socket.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <sys/time.h>  
#include <sys/ioctl.h>  
#include <unistd.h>  
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <errno.h>
#include <fcntl.h>

#define PORT 8877
#define RT_ERR (-1)
#define RT_OK 0
#define SERVERIP "172.18.201.128"
#define LISTEN_QUEUE 10
#define BUFFER_SIZE 1024
#define MAX_EVENTS 1024

int main(int argc, char *argv[])
{
    int listenfd, connsockfd, fd; 
    socklen_t len;
    char readbuf[BUFFER_SIZE];
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0)
    {
            fprintf(stderr, "socket function failed.\n");
            exit(RT_ERR);
    }

    struct sockaddr_in serveraddr, clientaddr;

//    bzero(&clientaddr, sizeof(clientaddr));

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = inet_addr(SERVERIP);

    unsigned int client_len = sizeof(struct sockaddr_in);
    if(bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
    {
            fprintf(stderr, "bind function failed.\n");
            close(listenfd);
            exit(RT_ERR);
    }

    if(listen(listenfd,LISTEN_QUEUE) < 0)
    {
            fprintf(stderr, "listen function failed.\n");
            close(listenfd);
        exit(RT_ERR);
    }
    int opts=fcntl(listenfd, F_GETFL);  
    if(opts<0)  
    {  
       fprintf(stderr, "fcntl(sock,GETFL)\n");  
       exit(-1);  
    } 
   
    opts = opts|O_NONBLOCK;  
    if(fcntl(listenfd,F_SETFL,opts)<0)  
    {  
       fprintf(stderr, "fcntl(sock,SETFL,opts)\n");  
       exit(-1);  
    }  

    fprintf(stdout, "The server IP is %s, listen on port: %d\n", inet_ntoa(serveraddr.sin_addr), ntohs(serveraddr.sin_port));
   
    struct epoll_event event, events[MAX_EVENTS];
    int epfd = epoll_create(MAX_EVENTS);
    event.data.fd=listenfd;  
    event.events=EPOLLIN|EPOLLET; 
    epoll_ctl(epfd,EPOLL_CTL_ADD,listenfd,&event);

    int nepfd, n;
    while(1)
    {
        nepfd = epoll_wait(epfd, events, MAX_EVENTS, 0);
        for(fd = 0; fd < nepfd; fd++)
        {
            bzero(&clientaddr, sizeof(clientaddr));
            fprintf(stdout, "fd is %d, listenfd is %d\n", fd, listenfd);
            if(events[fd].data.fd == listenfd)//新的请求连接用户
            {
    
                connsockfd = accept(listenfd, (struct sockaddr *)&clientaddr, &len);
                if(connsockfd < 0)
                {
                    fprintf(stderr, "accept function failed.\n");
                    exit(RT_ERR);
                }
                fprintf(stdout, "accept a new session from %s port:%d\n", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
    
                event.data.fd = connsockfd;
                event.events = EPOLLIN|EPOLLET; 
                epoll_ctl(epfd, EPOLL_CTL_ADD, connsockfd, &event);
             }
            else if(events[fd].events&EPOLLIN)//如果是已连接用户，有数据接收
            {
                struct sockaddr_in connaddr;
                int connlen;
                if((connsockfd = events[fd].data.fd) < 0)
                    continue;
                if((n = recv(connsockfd, readbuf, sizeof(readbuf), 0)) < 0) 
                {  
                     if (errno == ECONNRESET)
                     {  
                       close(connsockfd);  
                       events[fd].data.fd = -1;  
                     }
                     else 
                       fprintf(stderr, "recv function failed.\n");
                     } 
                     else if(n == 0)
                     {
                        close(connsockfd);  
                        events[fd].data.fd = -1;  
                      }
                 fprintf(stdout, "mesage: %s", readbuf);
                 event.data.fd = connsockfd;    
                      event.events = EPOLLOUT|EPOLLET;  
            }
            else if(events[fd].events&EPOLLOUT)//有数据发送
            {
                connsockfd = events[fd].data.fd;  
                     send(connsockfd, readbuf, sizeof(readbuf), 0);  
                     event.data.fd = connsockfd;  
                     event.events=EPOLLIN|EPOLLET;  
                      epoll_ctl(epfd, EPOLL_CTL_MOD, connsockfd, &event);    
            }
        }//end of for
    }//end of while
    return 0;
}

