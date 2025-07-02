#ifndef  _UDP_CLIENT_H
#define  _UDP_CLIENT_H

#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sched.h>
#include <unistd.h>
#include <stdio.h>

extern struct sockaddr_in server_add;
extern socklen_t len ; 
int setup_udp_client(const char *server_ip,int16_t Active_port);

#endif