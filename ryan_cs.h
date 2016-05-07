/*
 * ryan_cs.h
 *
 *  Created on: May 7, 2016
 *      Author: wang
 */

#ifndef RYAN_CS_H_
#define RYAN_CS_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#endif /* RYAN_CS_H_ */

void ryan_deal_listen_err(int err_no);
void ryan_server_before_accept(void);
void ryan_server_after_accept(int listenfd);
void ryan_server_accept_error(int err_no);
