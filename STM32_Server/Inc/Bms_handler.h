#ifndef _BMS_HANDLER_H
#define _BMS_HANDLER_H

#include "bms_can-config.h"
#include "bms_can.h"
#include "dbccodeconf.h"

// #define  MAX_BUFF  32

typedef struct{

  uint32_t can_id;
  uint32_t length;
  uint32_t payload[16];

}Ethernet_BMS_Packet;

extern Ethernet_BMS_Packet eth_msg;

typedef struct {

APP_flag_error_t status;
BAT_BMS_IntTemp_t status1;
BAT_BMS_ExtTemp_t status2;
BAT_AFE_Fet_Status_t status3;
BAT_BMS_Charger_Load_Status_t status4;
BMS_Temp_Sensor_Present_t status5;
BAT_GAUGE_OvrVIEW_t status6;
BAT_GAUGE_ViT_t status7;

}Struct_A;

extern Struct_A master_data;

int Bms_data_receive(int nClient);

#endif