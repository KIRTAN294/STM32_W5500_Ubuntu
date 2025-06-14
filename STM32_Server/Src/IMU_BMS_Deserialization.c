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

uint16_t Active_port = 6565;
uint8_t Number;

int server_fd;
int nClient;
Commandtype choice_enum;

void error(const char *msg);

int main(int argc, char *argv[])
{
  server_fd = setup_tcp_server(Active_port);
  nClient = wait_for_client(server_fd);

  while (1)
  {
    Input_Command();

    switch (choice_enum)
    {

    case Request_For_Buzzer:

      printf("Ringing Buzzer times : ");
      fgets(input, sizeof(input), stdin);
      sscanf(input, "%hhu", &Number);
      Command_To_STM(nClient, choice_enum, Number);
      break;

    case Request_For_BMS_Data:

      Command_To_STM(nClient, choice_enum, 0);
      Bms_data_receive(nClient);

      break;

    case Request_For_PDB_Data:

      Command_To_STM(nClient, choice_enum, 0);
      PDB_Data(nClient);
      break;

    case Request_For_IMU_Data:

      Command_To_STM(nClient, choice_enum, 0);
      Imu_data_receive(nClient);
      break;

    case Request_To_Kill:
    case Request_To_OFF_Front:
    case Request_To_OFF_Back:

      Command_To_STM(nClient, choice_enum, 0);
      sleep(1);
      break;
    }
  }
  close(nClient);
  close(server_fd);
  return 0;
}
