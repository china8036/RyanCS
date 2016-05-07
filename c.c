#ifndef RYAN_CS_H_
#define RYAN_CS_H_
#include "ryan_c.c"
#endif /* RYAN_CS_H_ */

int main(int argc, char** argv) {
	int connfd;
	int rev_len;
	if(argc < 3){
		printf("usage: ./c <ipaddress> <port>\n");
		return 0;
	}

	connfd = ryan_client_connect(argv[1], atoi(argv[2]));
	if(connfd != -1){
		rev_len = ryan_client_send(connfd, "hello world");
	}
	ryan_client_close(connfd);
	return 0;
}

void ryan_client_connect_err(int err_no){
	printf("connect error is： %s\n", strerror(err_no));

}
void ryan_client_ip_err(char *ip){
	printf("please input correct ip address!\n");
}
void ryan_client_send_suc(char *msg){
	printf("suc send %s \n", msg);

}
void ryan_client_send_fail(char *msg){
	printf("fail send %s \n", msg);
}
