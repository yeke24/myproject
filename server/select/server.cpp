#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int server_sockfd, client_sockfd;
    int server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    int result;
    fd_set readfds, testfds;

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);//允许任何ip连接
    server_address.sin_port = htons(9734);
    server_len = sizeof(server_address);


    bind(server_sockfd, (struct sockaddr*)&server_address, server_len);
    listen(server_sockfd, 5);

    FD_ZERO(&readfds);
    FD_SET(server_sockfd, &readfds);//将监听套接字放到可读集合中

    while(1)
    {
        char ch;
        int fd;
        int nread;

        testfds = readfds;

        printf("server waiting\n");

        //时间指针为0：表示一直阻塞，如果返回小于1表示程序出错
        result = select(FD_SETSIZE, &testfds,  (fd_set*)0, (fd_set*)0, (struct timeval*)0);
        if(result < 1){
            perror("server5");
            exit(1);
        }

        for(fd = 0; fd < FD_SETSIZE; ++fd){
            if(FD_ISSET(fd, &testfds)){
                if(fd == server_sockfd){//监听套接字可读表示，有新连接
                    client_len = sizeof(client_address);
                    client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_address, &client_len);
                    FD_SET(client_sockfd, &readfds);//将客户端套接字放到可读集合中
                    printf("adding client on fd %d\n", client_sockfd);
                }else{
                    ioctl(fd, FIONREAD, &nread);

                    if(nread == 0){//读到0字节表示客户端断开socket
                        close(fd);
                        FD_CLR(fd, &readfds);//将套接字从集合中清除
                        printf("removing client on fd %d\n", fd);
                    }else{
                    
                        read(fd, &ch, 1);
                        sleep(5);
                        printf("serving cient on fd  %d\n", fd);
                        ch++;
                        write(fd, &ch, 1);
                    }

                }
            }
        }

    }

return 0;
}