/*
 * Bms_handler.c
 *
 *  Created on: May 23, 2025
 *      Author: kirtan
 */

#include "Bms_handler.h"
#include "main.h"

bool Bms_message = false;

Master_BMS_Data_t master_data;
Ethernet_BMS_Packet eth_msg = {0};

void Handlebmsmessage(uint32_t can_id, uint8_t *RxData, uint8_t length){

	Bms_message = true;

	switch(can_id){

          case APP_flag_error_CANID:
	          eth_msg.can_id = APP_flag_error_CANID;
              Unpack_APP_flag_error_bms_can(&master_data.status, RxData, length);
              eth_msg.length = sizeof(master_data.status);
              memcpy(eth_msg.payload, &master_data.status, sizeof(master_data.status));
              break;

          case BAT_BMS_IntTemp_CANID:
	          eth_msg.can_id = BAT_BMS_IntTemp_CANID;
              Unpack_BAT_BMS_IntTemp_bms_can(&master_data.status1, RxData, length);
              eth_msg.length = sizeof(master_data.status1);
              memcpy(eth_msg.payload, &master_data.status1, sizeof(master_data.status1));
              break;

          case BAT_BMS_ExtTemp_CANID:
	          eth_msg.can_id = BAT_BMS_ExtTemp_CANID;
              Unpack_BAT_BMS_ExtTemp_bms_can(&master_data.status2, RxData, length);
              eth_msg.length = sizeof(master_data.status2);
              memcpy(eth_msg.payload, &master_data.status2, sizeof(master_data.status2));
              break;

          case BAT_AFE_Fet_Status_CANID:
	          eth_msg.can_id = BAT_AFE_Fet_Status_CANID;
              Unpack_BAT_AFE_Fet_Status_bms_can(&master_data.status3, RxData, length);
              eth_msg.length = sizeof(master_data.status3);
              memcpy(eth_msg.payload, &master_data.status3, sizeof(master_data.status3));

              break;

          case BAT_BMS_Charger_Load_Status_CANID:
	          eth_msg.can_id = BAT_BMS_Charger_Load_Status_CANID;
              Unpack_BAT_BMS_Charger_Load_Status_bms_can(&master_data.status4, RxData,length);
              eth_msg.length = sizeof(master_data.status4);
              memcpy(eth_msg.payload, &master_data.status4, sizeof(master_data.status4));
              break;

          case BMS_Temp_Sensor_Present_CANID:
	          eth_msg.can_id = BMS_Temp_Sensor_Present_CANID;
              Unpack_BMS_Temp_Sensor_Present_bms_can(&master_data.status5, RxData, length);
              eth_msg.length = sizeof(master_data.status5);
              memcpy(eth_msg.payload, &master_data.status5, sizeof(master_data.status5));
              break;

          case BAT_GAUGE_OvrVIEW_CANID:
	          eth_msg.can_id = BAT_GAUGE_OvrVIEW_CANID;
              Unpack_BAT_GAUGE_OvrVIEW_bms_can(&master_data.status6, RxData, length);
              eth_msg.length = sizeof(master_data.status6);
              memcpy(eth_msg.payload, &master_data.status6, sizeof(master_data.status6));
              break;

          case BAT_GAUGE_ViT_CANID:
	          eth_msg.can_id = BAT_GAUGE_ViT_CANID;
              Unpack_BAT_GAUGE_ViT_bms_can(&master_data.status7, RxData, length);
              eth_msg.length = sizeof(master_data.status7);
              memcpy(eth_msg.payload, &master_data.status7, sizeof(master_data.status7));
              break;

	}
}

void sendbmsdata(void)
{
    if (Bms_message && getSn_SR(TCP_SOCKET) == SOCK_ESTABLISHED)
    {

        int32_t sent = send(TCP_SOCKET, (uint8_t*)&eth_msg ,sizeof(Ethernet_BMS_Packet));

        if (sent > 0)
        {
            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0);
            Bms_message = false;
        }
        else
        {
            disconnect(TCP_SOCKET);
        }

    }
}
