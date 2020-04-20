#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>   
#include <sys/epoll.h>   
#include <netinet/in.h>   
#include <arpa/inet.h>   
#include <fcntl.h>
#include <errno.h>

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* End of #ifdef __cplusplus */

#define SERV_PORT           (5555)   
#define MAX_LISTENQ         (32)    
#define MAX_EVENT           (128) 
#define MAX_BUFSIZE         (512)   

int setNonBlocking(int p_nSock)
{   
    int nOpts;   
    nOpts=fcntl(p_nSock,F_GETFL);   
    if(nOpts<0)   
    {   
        printf("[%s %d] Fcntl Sock GETFL fail!\n",__FUNCTION__,__LINE__);
        return -1;
    }   

    nOpts = nOpts|O_NONBLOCK;   
    if(fcntl(p_nSock,F_SETFL,nOpts)<0)   
    {  
        printf("[%s %d] Fcntl Sock SETFL fail!\n",__FUNCTION__,__LINE__);
        return -1;   
    } 

    return 0;
}   

int main()
{
    int nRet,i;
    int nSockfd;
    int nAcceptfd;
    int nEventNum;   
    int nEpollfd;
    int nListenfd;

    struct sockaddr_in clientaddr;     
    struct sockaddr_in serveraddr;
    socklen_t clilen = sizeof(struct sockaddr_in);

    struct epoll_event ev;
    struct epoll_event events[MAX_EVENT];
  
    nEpollfd=epoll_create(MAX_EVENT);
    if (nEpollfd <= 0)
    {
        printf("[%s %d] Epoll Create fail return:%d!\n",__FUNCTION__,__LINE__,nEpollfd);
        return 0;
    }

    nListenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (nListenfd < 0)
    {
        printf("[%s %d] Socket Create fail return:%d!\n",__FUNCTION__,__LINE__,nListenfd);
        return 0;
    }

    if (setNonBlocking(nListenfd) < 0)
    {
        return 0;
    }

    memset(&serveraddr, 0x00, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;   
    serveraddr.sin_addr.s_addr=inet_addr("0.0.0.0");   
    serveraddr.sin_port=htons(SERV_PORT);   

    if (bind(nListenfd,(struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
    {
        printf("[%s %d] Bind fd fail!\n",__FUNCTION__,__LINE__);
        return 0;
    }

    if (listen(nListenfd,MAX_LISTENQ) < 0)
    {
        printf("[%s %d] Listen fd fail!\n",__FUNCTION__,__LINE__);
        return 0;
    } 

    ev.data.fd=nListenfd;        
    ev.events=EPOLLIN;//默认使用EPOLLLT模式    
    if (epoll_ctl(nEpollfd,EPOLL_CTL_ADD,nListenfd,&ev) < 0)
    {
        printf("[%s %d] Epoll ctl error!\n",__FUNCTION__,__LINE__);
        return 0;
    }

    char szRecvBuf[MAX_BUFSIZE];
    memset(szRecvBuf,0x0,MAX_BUFSIZE); 

    for (;;)    
    {   
        nEventNum = epoll_wait(nEpollfd, events, MAX_EVENT, -1);
        printf("events num:%d\n",nEventNum);
        for ( i = 0;  i<nEventNum; i++ )
        {   

            if ((events[i].events & EPOLLERR) ||  
                    (events[i].events & EPOLLHUP))  
            {  
                printf("[%s %d] Epoll Event Error!\n",__FUNCTION__,__LINE__);
                close (events[i].data.fd);  
                continue;  
            }
            else if (nListenfd == events[i].data.fd)  
            {
                printf("[%d] Listenfd:%d,events[i].data.fd:%d\n", __LINE__,nListenfd,events[i].data.fd);

                nAcceptfd = accept(nListenfd, (struct sockaddr*)&clientaddr, &clilen);
                if(nAcceptfd < 0)
                {
                    printf("[%s %d] Accept fd fail return:%d!\n",__FUNCTION__,__LINE__,nAcceptfd);
                    continue;
                }

                printf("[%d] Acceptfd:%d,IP:%s,Port:%d\n",__LINE__,nAcceptfd,inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
                if (setNonBlocking(nAcceptfd) < 0)
                {
                    continue;
                }

                ev.data.fd = nAcceptfd;// 将新连接也加入EPOLL的监听队列
                ev.events = EPOLLIN | EPOLLET ;
                if(epoll_ctl(nEpollfd, EPOLL_CTL_ADD, nAcceptfd, &ev)< 0)
                {
                    printf("[%s %d] Epoll ctl error!\n",__FUNCTION__,__LINE__);
                    continue;
                }

                continue;
            }

            if(events[i].events&EPOLLIN)                   
            {   
                if ((nSockfd = events[i].data.fd) < 0)
                {
                    continue;
                }

                printf("[%s %d] EPOLLIN Sockfd:%d\n",__FUNCTION__,__LINE__,nSockfd);

                memset(szRecvBuf, 0x00, sizeof(szRecvBuf));
                if ( (nRet = recv(nSockfd, szRecvBuf, MAX_BUFSIZE,0)) < 0)   
                {  
                    printf("[%s %d] Recv Data nRet:%d, error:%s!\n",__FUNCTION__,__LINE__,nRet,strerror(errno));
                    if (errno == ECONNRESET)
                    {
                        close(nSockfd);  
                        epoll_ctl(nEpollfd,EPOLL_CTL_DEL,nSockfd,&ev);  
                        events[i].data.fd = -1;
                    }

                    continue;
                } 
                else if (nRet == 0)   
                {   
                    printf("[%s %d] Recv error, client had closed!\n",__FUNCTION__,__LINE__);
                    close(nSockfd);  
                    epoll_ctl(nEpollfd,EPOLL_CTL_DEL,nSockfd,&ev);  
                    events[i].data.fd = -1;
                    continue;
                } 

                printf("\n******************************\n");
                printf("**RecvData:%s\n",szRecvBuf);
                printf("******************************\n");
             
                ev.data.fd = nSockfd;            
                ev.events = EPOLLOUT | EPOLLET;
                epoll_ctl(nEpollfd, EPOLL_CTL_MOD, nSockfd, &ev);
            }
            else if(events[i].events&EPOLLOUT)                 
            {    
                if ((nSockfd = events[i].data.fd) < 0)
                {
                    continue;
                }

                printf("[%s %d] EPOLLOUT Sockfd:%d\n", __FUNCTION__, __LINE__, nSockfd);

                nRet = send(nSockfd, szRecvBuf, strlen(szRecvBuf), 0);
                printf("[%s %d] Send Len:%d\n", __FUNCTION__, __LINE__, nRet);
                 
                ev.data.fd = nSockfd;
                ev.events = EPOLLIN | EPOLLET;
                epoll_ctl(nEpollfd, EPOLL_CTL_MOD, nSockfd, &ev);
            }   
        }   
    }  

    close(nListenfd);
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

