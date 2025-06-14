#include "tcp_server.h"
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <errno.h>
#include <sched.h>
#include <unistd.h>
#include <stdio.h>


static void error(const char *msg){
    perror(msg);
    exit(-1);
}

int setup_tcp_server(uint16_t Active_port){

   int server_fd;
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
     if (server_fd < 0) {
        error("ERROR opening socket\n");
      }

  struct sockaddr_in server_add = {
    .sin_family = AF_INET,
    .sin_addr.s_addr = INADDR_ANY,
    .sin_port = htons(Active_port)
    };   

    memset(&(server_add.sin_zero),0,8);
    
    int opt = 1;
      if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
       error("setsockopt(SO_REUSEADDR) failed");
       exit(1);
     }

     if (bind(server_fd, (struct sockaddr *) &server_add, sizeof(server_add)) < 0) {
        error("ERROR on binding\n");
       }
     if (listen(server_fd,5)){
        error("\nCan't listen at port");
       }  
   return server_fd;   
}

int wait_for_client(int server_fd){

  struct sockaddr_in client_add ;  
  socklen_t addrlen = sizeof(client_add);
  int nClient = 0;
    nClient = accept(server_fd,(struct sockaddr*)&client_add,&addrlen);
      if (nClient < 0)
      {
      error("\nCan't listen at port");
      }

  int nodelay = 1;
  setsockopt(nClient, IPPROTO_TCP, TCP_NODELAY, (char*)&nodelay, sizeof(nodelay));

  return nClient;
}