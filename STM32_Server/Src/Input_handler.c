#include "Input_handler.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>


char input[16];
int nRet;
int valid = 0;

void Input_Command(void)
{

    printf("\nEnter command:\n");
    printf("1 - Request_For_IMU_Data \n");
    printf("2 - Request_For_BMS_Data \n");
    printf("3 - Request_For_PDB_Data \n");
    printf("4 - Request_To_Kill\n");
    printf("5 - Request_To_OFF_Front\n");
    printf("6 - Request_To_OFF_Back\n");
    printf("7 - Request_For_Buzzer\n");
    printf("Your choice_enum: ");

    if (fgets(input, sizeof(input), stdin) != NULL)
    {
        input[strcspn(input, "\n")] = 0;
        int is_digit = 1;
        for (int i = 0; i < strlen(input); i++)
        {
            if (!isdigit((unsigned char)input[i]))
            {
                is_digit = 0;
                break;
            }
        }
        if ((is_digit && sscanf(input, "%d", (int *)&choice_enum) == 1 && choice_enum >= Request_For_IMU_Data && choice_enum <= Request_For_Buzzer) != 1)
        {
            printf("Invalid choice_enum.\n");
            exit(0);
        }
    }
}

void Command_To_STM(int nClient, Commandtype choice_enum, uint8_t Numtimes)
{

    typedef struct
    {
        Commandtype cmd;
        uint8_t Number;

    } CommandPacket;
    CommandPacket Packet;

    Packet.cmd = choice_enum;
    Packet.Number = Numtimes;

    nRet = send(nClient, &Packet, sizeof(Packet), 0);
    if (nRet != sizeof(Packet))
    {
        printf("\nFailed to send complete command: sent %d bytes, expected %lu, error: %d\n",
               nRet, sizeof(Packet), errno);
        return;
    }
    printf("Request & Number sent to client: %d & %d\n", Packet.cmd, Packet.Number);
}