#ifndef RYAN_CS_H_
#define RYAN_CS_H_
#include "ryan_c.c"
#endif /* RYAN_CS_H_ */
#define MAX 1024
int main(int argc, char** argv) {
	int connfd,recv_len;
	int rev_len;
	char sendline[MAX], recvmsg[MAX];
	if(argc < 3){
		printf("usage: ./c <ipaddress> <port>\n");
		return 0;
	}

	connfd = ryan_client_connect(argv[1], atoi(argv[2]));
	while(connfd != -1){
		memset(&sendline, 0, sizeof(sendline));
		printf("Send:");
		fgets(sendline, MAX, stdin);
		rev_len = ryan_client_send(connfd, sendline);
		if(rev_len == -1){
			printf("send fail:%s\n", strerror(errno));
			break;
		}
		memset(&recvmsg, 0, sizeof(recvmsg));
		recv_len = ryan_client_recv(connfd, recvmsg,  MAX);
		if(recv_len == -1){
			printf("rev error:%s\n", strerror(errno));
		}
		printf("Rev:%s", recvmsg);
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
	//printf("sended\n");

}
void ryan_client_send_fail(char *msg){
	printf("fail send %s \n", msg);
}
