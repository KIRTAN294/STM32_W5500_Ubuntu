#include "Imu_handler.h"
#include "tcp_server.h"
#include "Bms_handler.h"
#include  <stdio.h>
#include  <errno.h>
#include  <sys/socket.h>
#include  <unistd.h>

#define Send_IMU_Data 1
#define Send_BMS_Data 2

typedef uint8_t Commandtype;

void error(const char *msg); 
 
int main(int argc, char *argv[]) {

   uint16_t port = 6565;
   int nRet;

   int server_fd = setup_tcp_server(port);
   int nClient = wait_for_client (server_fd);

   int choice;
    printf("Enter command:\n");
    printf("1 - Request IMU Data\n");
    printf("2 - Request BMS Data\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    
    if (choice != Send_IMU_Data && choice != Send_BMS_Data) {
        error("Invalid choice.\n");
        return -1;
    }
    
  Commandtype User_Input = (Commandtype)choice;

   nRet = send(nClient,&User_Input, sizeof(User_Input), 0);
    if (nRet != sizeof(User_Input)) {
       printf("\nFailed to send complete command: sent %d bytes, expected %ld, error: %d\n", 
              nRet, sizeof(User_Input), errno);
       return -1;
    }
       printf("Request sent to client: %d\n", User_Input);

 while(1){
  
  if ( choice == Send_IMU_Data)  {

      Imu_data_receive(nClient);

    } 
  else if( choice == Send_BMS_Data) {

      Bms_data_receive(nClient);

    }
  }
close(nClient);
close(server_fd);
return 0;
}


