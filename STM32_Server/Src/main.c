#include "Imu_handler.h"
#include "tcp_client.h"
#include "udp_client.h"
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

int TCP_client_fd;
int UDP_client_fd;
Commandtype choice_enum;

void error(const char *msg);

int main(int argc, char *argv[])
{
  if (argc >= 2)
  {
    Active_port = (uint16_t)atoi(argv[1]);

    if (Active_port == 6666)
    {
      TCP_client_fd = setup_tcp_client(server_ip, Active_port);

    }
    else if (Active_port == 4444 || Active_port == 3333 || Active_port == 5555)
    {
      const char *server_ip_udp = "176.162.10.255";
      UDP_client_fd = setup_udp_client(server_ip_udp, Active_port);
    }
    else
    {
      printf("Invalid port: %d. Use a port between 5555 and 5558.\n", Active_port);
      return -1;
    }
  }
  else
  {
    printf("Usage: %s <port>\n", argv[0]);
    return -1;
  }

  while (1)
  {
    switch (Active_port)
    {
    case 3333:
      Imu_data_receive(UDP_client_fd);
      break;

    case 4444:
      Bms_data_receive(UDP_client_fd);
      break;
   
    case 5555:
      PDB_Data(UDP_client_fd);
      break;
      
    case 6666:

      Input_Command();
      switch (choice_enum)
      {

        // case Request_For_IMU_Data:
        //   Command_To_STM(TCP_client_fd, choice_enum, 0);
        //   Imu_data_receive(TCP_client_fd);
        //   break;

        // case Request_For_BMS_Data:
        //   Command_To_STM(TCP_client_fd, choice_enum, 0);
        //   Bms_data_receive(TCP_client_fd);
        //   break;

        // case Request_For_PDB_Data:

        //   Command_To_STM(TCP_client_fd, choice_enum, 0);
        //   PDB_Data(TCP_client_fd);
        //   break;

      case Request_To_Kill:
      case Request_To_OFF_Front:
      case Request_To_OFF_Back:

        Command_To_STM(TCP_client_fd, choice_enum, 0);
        sleep(1);
        break;

      case Request_For_Buzzer:

        printf("Ringing Buzzer times : ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%hhu", &Number);
        Command_To_STM(TCP_client_fd, choice_enum, Number);
        break;
      }
    }
  }
  close(TCP_client_fd);
  return 0;
}
