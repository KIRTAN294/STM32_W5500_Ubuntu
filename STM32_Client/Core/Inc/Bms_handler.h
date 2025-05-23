/*
 * Bms_handler.h
 *
 *  Created on: May 23, 2025
 *      Author: kirtan
 */

#ifndef INC_BMS_HANDLER_H_
#define INC_BMS_HANDLER_H_

#include "main.h"

extern bool Bms_message;

typedef struct{

	uint32_t can_id;
	uint32_t length;
	uint32_t payload[16];

}Ethernet_BMS_Packet;
extern Ethernet_BMS_Packet eth_msg ;

typedef struct {

    APP_flag_error_t status;
    BAT_BMS_IntTemp_t status1;
    BAT_BMS_ExtTemp_t status2;
    BAT_AFE_Fet_Status_t status3;
    BAT_BMS_Charger_Load_Status_t status4;
    BMS_Temp_Sensor_Present_t status5;
    BAT_GAUGE_OvrVIEW_t status6;
    BAT_GAUGE_ViT_t status7;

} Master_BMS_Data_t;

extern Master_BMS_Data_t master_data;

void sendbmsdata(void);
void Handlebmsmessage(uint32_t can_id, uint8_t *data, uint8_t length);
#endif /* INC_BMS_HANDLER_H_ */
