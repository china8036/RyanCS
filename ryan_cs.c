#ifndef RYAN_CS_H_
#define RYAN_CS_H_
#include "ryan_cs.h"
#endif /* RYAN_CS_H_ */

int ryan_server_start(short int port, int wait_num){
    int    listenfd;
    struct sockaddr_in     servaddr;

    if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){//主要是选协议
        ryan_deal_listen_err(errno);
        return -1;
    }
    memset(&servaddr, 0, sizeof(servaddr));//全部设置为0
    servaddr.sin_family = AF_INET;//
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);//本机地址并按网络字节排序
    servaddr.sin_port = htons(port);//端口号并按网络字节顺序排序
//绑定端口号
    if( bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        ryan_deal_listen_err(errno);
        return -1;

    }
//开始监听并写入队列 10标示最多存取10个等待链接
    if( listen(listenfd, wait_num) == -1){
        ryan_deal_listen_err(errno);
    	return -1;
    }
   return listenfd;
}

int ryan_server_accept(int listenfd){
    int connfd;
    ryan_server_before_accept();
    if( (connfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) == -1){
        ryan_server_accept_error(errno);
        return -1;
    }
    ryan_server_after_accept(listenfd);
    return connfd;

}

int ryan_server_rev(int connfd,	 char* buff, int max){
  int n ;
  n = recv(connfd, buff, max, 0);
  buff[n] = '\0';
  return n;
}

int ryan_server_close(int listenfd, int connfd){
	if(listenfd != -1){
        	close(listenfd);
        }
	if(connfd != -1){
		close(connfd);
	}
	return 0;
}
