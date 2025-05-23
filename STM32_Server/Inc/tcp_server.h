#ifndef  _TCP_SERVER_H
#define  _TCP_SERVER_H

#include <stdint.h>


int setup_tcp_server(uint16_t port);
int wait_for_client (int server_fd);


#endif