#include "tcp_server.h"
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

static void error(const char *msg)
{
  perror(msg);
  exit(-1);
}

int setup_tcp_client(const char *server_ip,int16_t Active_port)
{

  int server_fd;
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0)
  {
    error("ERROR opening socket\n");
  }

  struct sockaddr_in server_add = {
      .sin_family = AF_INET,
      .sin_addr.s_addr = inet_addr(server_ip),
      .sin_port = htons(Active_port)};

  memset(&(server_add.sin_zero), 0, 8);

  int C = connect(server_fd, (struct sockaddr *)&server_add, sizeof(server_add));
  if (C == -1)
  {
    error("Connction is not established");
  }

  return server_fd;
}

