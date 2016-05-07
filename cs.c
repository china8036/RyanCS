#ifndef RYAN_CS_H_
#define RYAN_CS_H_
#include "ryan_cs.c"
#endif /* RYAN_CS_H_ */

int main(void){
     int listenfd, connfd;
     char rev[100];
     int max = 100, rev_len;

     listenfd =  ryan_server_start(6666,10);
     connfd = ryan_server_accept(listenfd);
     rev_len = ryan_server_rev(connfd, rev, max);
     if(rev_len == -1){
     	printf("rev error\n");
        return 0;
     }
     printf("rev str is %s,len is %d\n", rev, rev_len);
     ryan_server_close(listenfd, connfd);
     return 0;
}
void ryan_deal_listen_err(int err_no){}
void ryan_server_accept_error(int err_no){}
void ryan_server_before_accept(void){
	printf("========Hello Im ready for you connect=========\n");
}
void ryan_server_after_accept(int listenfd){
      printf("welcome!\n");
}
