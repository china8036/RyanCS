#ifndef RYAN_CS_H_
#define RYAN_CS_H_
#include "ryan_c.c"
#endif /* RYAN_CS_H_ */

int main(void) {
	int connfd;
	char rev[100];
	int max = 100, rev_len;

	connfd = ryan_client_connect("127.0.0.1", 6666);
	if(connfd != -1){
		rev_len = ryan_client_send(connfd, "hello world");
	}
	return 0;
}

void ryan_client_connect_err(int err_no){
	printf("connect error is： %s\n", strerror(err_no));

}
void ryan_client_ip_err(char *ip){}
void ryan_client_send_suc(char *msg){
	printf("suc send %s \n", msg);

}
void ryan_client_send_fail(char *msg){
	printf("fail send %s \n", msg);
}
