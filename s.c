#ifndef RYAN_CS_H_
#define RYAN_CS_H_
#include "ryan_s.c"
#endif /* RYAN_CS_H_ */
#define MAX 1024
int main(int argc, char** argv) {
	int listenfd, connfd;
	char rev[100],sendline[MAX];
	int max = 100, rev_len;
	if(argc < 2){
		printf("usage: ./s <port>\n");
		return 0;
	}
	listenfd = ryan_server_start(atoi(argv[1]), 10);
	while(1){//循环等待端链接
		if(listenfd != -1){
			connfd = ryan_server_accept(listenfd);
		}
		while(connfd > -1){//每一个链接接受多次发送
			rev_len = ryan_server_recv(connfd, rev, max);
			if (rev_len < 1) {
				break;
			}else{
				printf("Rev:%s", rev);
				printf("Send:");
				fgets(sendline, MAX, stdin);
				ryan_server_send(connfd, sendline);
			}
		}
	}
	ryan_server_close(listenfd, connfd);
	return 0;
}
void ryan_server_listen_err(int err_no) {
	printf("listen error \n");
}
void ryan_server_accept_error(int err_no) {
	printf("accept error\n");
}
void ryan_server_before_accept(void) {
	printf("========Hello Im ready for you connect=========\n");
}
void ryan_server_after_accept(int listenfd) {
	printf("welcome!\n");
}
