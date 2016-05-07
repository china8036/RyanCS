#ifndef RYAN_CS_H_
#define RYAN_CS_H_
#include "ryan_s.c"
#endif /* RYAN_CS_H_ */

int main(int argc, char** argv) {
	int listenfd, connfd;
	char rev[100];
	int max = 100, rev_len;
	if(argc < 2){
		printf("usage: ./s <port>\n");
		return 0;
	}
	listenfd = ryan_server_start(atoi(argv[1]), 10);
	if(listenfd != -1){
		connfd = ryan_server_accept(listenfd);
	}
	if(connfd > -1){
		rev_len = ryan_server_rev(connfd, rev, max);
	}
	if (rev_len == -1) {
		printf("rev error\n");
		return 0;
	}
	printf("rev str is %s,len is %d\n", rev, rev_len);
	ryan_server_close(listenfd, connfd);
	return 0;
}
void ryan_server_listen_err(int err_no) {
}
void ryan_server_accept_error(int err_no) {
}
void ryan_server_before_accept(void) {
	printf("========Hello Im ready for you connect=========\n");
}
void ryan_server_after_accept(int listenfd) {
	printf("welcome!\n");
}
