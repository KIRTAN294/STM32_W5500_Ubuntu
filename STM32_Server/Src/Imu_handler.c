#define _GNU_SOURCE
#include "Imu_handler.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <errno.h>
#include <sys/socket.h>

#define BUFFER_IMU_SIZE  28
#define MAX_MESSAGES (BUFFER_IMU_SIZE/ sizeof(EulerAngles))
unsigned char buffer[BUFFER_IMU_SIZE] = {0};
int total_received = 0;

EulerAngles angles;

static void error(const char *msg){
    perror(msg);
    exit(-1);
}
int Imu_data_receive(int nClient){
  
   int nRet; 
     while (1){
      
      // printf("Running on CPU %d\n", sched_getcpu());

      nRet = recv(nClient, buffer+total_received, sizeof(buffer)-total_received, 0);
      if (nRet == 0) {
          printf("Connection closed by client\n");
          break;
          }

      if (nRet < 0) {
            error("Receive  error:");
              break;
          }    

      if (nRet > 0) {
          total_received += nRet;
          send(nClient, "OK", 2, 0);
          int complete_messages = total_received / sizeof(EulerAngles);

      for (int i = 0; i < complete_messages; i++) {
      
       memcpy(&angles, buffer + (i * sizeof(EulerAngles)), sizeof(EulerAngles));

       printf("TimeStamp: %u, Roll: %.2f, Pitch: %.2f, Yaw: %.2f, AccX: %.2f, AccY: %.2f, AccZ: %.2f \r\n",
          angles.timestamp, angles.roll, angles.pitch, angles.yaw,
          angles.accx, angles.accy, angles.accz);
      }

      if (nRet < 0)
      {
      error("\nCan't recv message:");
        return -1;
      }

      if (complete_messages > 0) {
      int remaining = total_received - (complete_messages * sizeof(EulerAngles));
      if (remaining > 0) {
          memmove(buffer, buffer + (complete_messages * sizeof(EulerAngles)), remaining);
      }
      total_received = remaining;
      }
    }
  }

   return nClient;
}