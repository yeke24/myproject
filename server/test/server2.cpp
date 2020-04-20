#include	<sys/types.h>	/* basic system data types */
#include	<sys/socket.h>	/* basic socket definitions */
#include	<sys/time.h>	/* timeval{} for select() */
#include	<time.h>		/* timespec{} for pselect() */
#include	<netinet/in.h>	/* sockaddr_in{} and other Internet defns */
#include	<arpa/inet.h>	/* inet(3) functions */
#include	<errno.h>
#include	<fcntl.h>		/* for nonblocking */
#include	<netdb.h>
#include	<signal.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/stat.h>	/* for S_xxx file mode constants */
#include	<sys/uio.h>		/* for iovec{} and readv/writev */
#include	<unistd.h>
#include	<sys/wait.h>
#include	<sys/un.h>	/* for Unix domain sockets */

const int  LISTENQ=1024;
//#define LISTENQ 1024

ssize_t						/* Write "n" bytes to a descriptor. */
writen(int fd, const void *vptr, size_t n)
{
	size_t		nleft;
	ssize_t		nwritten;
	const char	*ptr;

	ptr = vptr;
	nleft = n;
	while (nleft > 0) {
		if ( (nwritten = write(fd, ptr, nleft)) <= 0) {
			if (nwritten < 0 && errno == EINTR)
				nwritten = 0;		/* and call write() again */
			else
				return(-1);			/* error */
		}

		nleft -= nwritten;
		ptr   += nwritten;
	}
	return(n);
}

int main(int argc, char **argv)
{
int listenfd,connfd;
pid_t childpid;
socklen_t clilen;
struct sockaddr_in cliaddr, servaddr;

listenfd = socket(AF_INET,SOCK_STREAM,0);
//memset(&servaddr,0,sizeof(servaddr));

bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family      =AF_INET;
servaddr.sin_addr.s_addr =htonl(INADDR_ANY);
servaddr.sin_port         =htons(110);

bind(listenfd,(struct sockaddr*)&servaddr, sizeof(servaddr));

listen(listenfd,LISTENQ);

for( ; ; )
{
clilen = sizeof(cliaddr);
connfd = accept(listenfd, (struct sockaddr*)&cliaddr,&clilen);

if((childpid=fork())==0)
{
	close(listenfd);
	char	buf[1024];	
	ssize_t n;

	while ( (n= read(connfd, buf, 1024)) > 0)
		writen(connfd, buf, n);
}

close(connfd);
}

return 0;
}

