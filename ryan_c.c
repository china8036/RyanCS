#ifndef RYAN_CS_H_
#define RYAN_CS_H_
#include "ryan_cs.h"
#endif /* RYAN_CS_H_ */

void ryan_client_connect_err(int err_no);
void ryan_client_ip_err(char *ip);
void ryan_client_send_suc(char *msg);
void ryan_client_send_fail(char *msg);

int ryan_client_connect(char *ser_ip, short int ser_port) {
	int sockfd, n;
	struct sockaddr_in servaddr;

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		ryan_client_connect_err(errno);
		return -1;
	}
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(ser_port);
	if (inet_pton(AF_INET, ser_ip, &servaddr.sin_addr) <= 0) {
		ryan_client_ip_err(ser_ip);
		return -1;
	}
	if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
		ryan_client_connect_err(errno);
		return -1;
	}
	return sockfd;;
}

void ryan_client_send(int sockfd, char * msg) {
	if (send(sockfd, msg, strlen(msg), 0) < 0) {
		ryan_client_send_fail(msg);
	} else {
		ryan_client_send_suc(msg);
	}
}

int ryan_client_recv(int sockfd, void * msg, size_t len) {
	return recv(sockfd, msg, len, 0);
}

void ryan_client_close(int sockfd) {
	if (sockfd != -1) {
		close(sockfd);
	}
}
