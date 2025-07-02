#include "udp_client.h"
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

int setup_udp_client(const char *server_ip, int16_t Active_port)
{
  int UDP_client_fd;

  if (Active_port == 4444)
  {

    UDP_client_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (UDP_client_fd < 0)
    {
      error("ERROR opening in TCP socket\n");
    }

    struct sockaddr_in server_add = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = inet_addr(server_ip),
        .sin_port = htons(Active_port)};

    memset(&(server_add.sin_zero), 0, 8);

    if (bind(UDP_client_fd, (struct sockaddr *)&server_add, sizeof(server_add)) < 0)
      error("bind failed");

    return UDP_client_fd;
  }

  else if (Active_port == 3333)
  {

    UDP_client_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (UDP_client_fd < 0)
    {
      error("ERROR opening in TCP socket\n");
    }
    struct sockaddr_in server_add = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = inet_addr(server_ip),
        .sin_port = htons(Active_port)};

    memset(&(server_add.sin_zero), 0, 8);

    if (bind(UDP_client_fd, (struct sockaddr *)&server_add, sizeof(server_add)) < 0)
      error("bind failed");

    return UDP_client_fd;
  }

  else if (Active_port == 5555)
  {

    UDP_client_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (UDP_client_fd < 0)
    {
      error("ERROR opening in TCP socket\n");
    }
    struct sockaddr_in server_add = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = inet_addr(server_ip),
        .sin_port = htons(Active_port)};

    memset(&(server_add.sin_zero), 0, 8);

    if (bind(UDP_client_fd, (struct sockaddr *)&server_add, sizeof(server_add)) < 0)
      error("bind failed");

    return UDP_client_fd;
  }
}
