#ifndef _INPUT_HANDLER_H
#define _INPUT_HANDLER_H

#include <stdint.h>


typedef enum
{
  Request_For_IMU_Data = 1,
  Request_For_BMS_Data = 2,
  Request_For_PDB_Data = 3,
  Request_To_Kill = 4,
  Request_To_OFF_Front = 5,
  Request_To_OFF_Back = 6,
  Request_For_Buzzer = 7,

} Commandtype;

extern Commandtype choice_enum;
extern char input[16];

void Input_Command(void);
void Command_To_STM(int nClient,Commandtype choice_enum,uint8_t Numtimes);

#endif