#include "Imu_handler.h"
#include "tcp_server.h"
#include "Bms_handler.h"
#include "Pdb_handler.h"
#include "Input_handler.h"
#include <stdio.h>
#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

uint16_t Active_port;
const char *server_ip = "176.162.10.1";
uint8_t Number;

int server_fd;
Commandtype choice_enum;

void error(const char *msg);

int main(int argc, char *argv[])
{
   if (argc >= 2) {
        Active_port = (uint16_t)atoi(argv[1]);
        
    if (Active_port < 5555 || Active_port > 5558) {
        printf("Invalid port: %d. Use a port between 5555 and 5558.\n", Active_port);
        return -1;

        }
    } else {
        printf("Usage: %s <port>\n", argv[0]);
        return -1;
    }
  server_fd = setup_tcp_client(server_ip,Active_port);

  while (1)
  {
    Input_Command();

    switch (choice_enum)
    {

    case Request_For_Buzzer:

      printf("Ringing Buzzer times : ");
      fgets(input, sizeof(input), stdin);
      sscanf(input, "%hhu", &Number);
      Command_To_STM(server_fd,choice_enum, Number);
      break;

    case Request_For_BMS_Data:

      Command_To_STM(server_fd, choice_enum, 0);
      Bms_data_receive(server_fd);

      break;

    case Request_For_PDB_Data:

      Command_To_STM(server_fd, choice_enum, 0);
      PDB_Data(server_fd);
      break;

    case Request_For_IMU_Data:

      Command_To_STM(server_fd, choice_enum, 0);
      Imu_data_receive(server_fd);
      break;

    case Request_To_Kill:
    case Request_To_OFF_Front:
    case Request_To_OFF_Back:

      Command_To_STM(server_fd, choice_enum, 0);
      sleep(1);
      break;
    }
  }
  close(server_fd);
  return 0;
}
