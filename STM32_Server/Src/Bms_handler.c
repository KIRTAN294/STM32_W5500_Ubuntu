#include "Bms_handler.h"
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#define TOTAL_SIZE  sizeof(Ethernet_BMS_Packet)

Ethernet_BMS_Packet eth_msg;
Struct_A master_data;

int Bms_data_receive(int nClient){

    int nRet;

  while (1){

    int total_received = 0;

    while (total_received < TOTAL_SIZE)
    {
        nRet = recv(nClient, ((uint8_t*)&eth_msg) +total_received, TOTAL_SIZE - total_received, 0);
        if (nRet == 0) {
            printf("Connection closed by client\n");
            break;
            }
            if (nRet < 0) {
             perror("Receive error"); 
            break;
} 
         total_received += nRet;     
    }
    if (total_received >= TOTAL_SIZE) {

      switch(eth_msg.can_id){
               
         case APP_flag_error_CANID:
            memcpy(&master_data.status, eth_msg.payload, sizeof(master_data.status));
            break;

        case BAT_BMS_IntTemp_CANID:
            memcpy(&master_data.status1, eth_msg.payload,sizeof(master_data.status1));
            break;

        case BAT_BMS_ExtTemp_CANID:
            memcpy(&master_data.status2, eth_msg.payload, sizeof(master_data.status2));
            break;

        case BAT_AFE_Fet_Status_CANID:
            memcpy(&master_data.status3, eth_msg.payload, sizeof(master_data.status3));
            break;

        case BAT_BMS_Charger_Load_Status_CANID:
            memcpy(&master_data.status4, eth_msg.payload, sizeof(master_data.status4));
            break;

        case BMS_Temp_Sensor_Present_CANID:
            memcpy(&master_data.status5, eth_msg.payload, sizeof(master_data.status5));
            break;

        case BAT_GAUGE_OvrVIEW_CANID:
            memcpy(&master_data.status6, eth_msg.payload, sizeof(master_data.status6));
            break;

        case BAT_GAUGE_ViT_CANID:
            memcpy(&master_data.status7, eth_msg.payload, sizeof(master_data.status7));
            break;

        default:
            printf("Wrong ID:%u\n",eth_msg.can_id);
            continue;
      }
            printf("APP_flag_bat_highTemp : %d\n",master_data.status.APP_flag_bat_highTemp);
            printf("APP_flag_bat_lowTemp  : %d\n",master_data.status.APP_flag_bat_lowTemp);
            printf("APP_flag_bms_highTemp : %d\n",master_data.status.APP_flag_bms_highTemp);
            printf("APP_flag_bms_lowTemp  : %d\n",master_data.status.APP_flag_bms_lowTemp);
            printf("APP_flag_highCurrent  : %d\n",master_data.status.APP_flag_highCurrent);
            printf("APP_flag_overvolt     : %d\n",master_data.status.APP_flag_overvolt);
            printf("APP_flag_scd_error    : %d\n",master_data.status.APP_flag_scd_error);
            printf("APP_flag_undervolt    : %d\n",master_data.status.APP_flag_undervolt);
            printf("\n\n");

            printf("BAT_bms_ambient_temp_ro : %d\n",master_data.status1.BAT_bms_ambient_temp_ro);
            printf("BAT_bms_ambient_temp_phy: %f\n",master_data.status1.BAT_bms_ambient_temp_phys);
            printf("BAT_bms_fets_temp_ro    : %d\n",master_data.status1.BAT_bms_fets_temp_ro);
            printf("BAT_bms_fets_temp_phys  : %f\n",master_data.status1.BAT_bms_fets_temp_phys);
            printf("\n\n");

            printf("BAT_bms_afe_temp1_ro  : %d\n",master_data.status2.BAT_bms_afe_temp1_ro);
            printf("BAT_bms_afe_temp1_phys: %f\n",master_data.status2.BAT_bms_afe_temp1_phys);
            printf("BAT_bms_afe_temp2_ro  : %d\n",master_data.status2.BAT_bms_afe_temp2_ro);
            printf("BAT_bms_afe_temp2_phys: %f\n",master_data.status2.BAT_bms_afe_temp2_phys);
            printf("BAT_bms_ext_temp1     : %d\n",master_data.status2.BAT_bms_ext_temp1);
            printf("BAT_bms_ext_temp2     : %d\n",master_data.status2.BAT_bms_ext_temp2);
            printf("\n\n");

            printf("BAT_afe_chg  : %hu\n",master_data.status3.BAT_afe_chg);
            printf("BAT_afe_dchg : %hu\n",master_data.status3.BAT_afe_dchg);
            printf("BAT_afe_pchg : %hu\n",master_data.status3.BAT_afe_pchg);
            printf("BAT_afe_pdsg : %hu\n",master_data.status3.BAT_afe_pdsg);
            printf("BAT_afe_dchg : %hu\n",master_data.status3.BAT_afe_dchg);
            printf("BAT_afe_ddsg : %hu\n",master_data.status3.BAT_afe_ddsg);
            printf("\n\n");

            printf("APP_bms_load_detect    : %d\n",master_data.status4.APP_bms_load_detect);
            printf("APP_bms_charger_detect : %d\n",master_data.status4.APP_bms_charger_detect);
            printf("\n\n");

            printf("BMS_ambient_temp_sensor_present : %d\n",master_data.status5.BMS_ambient_temp_sensor_present);
            printf("BMS_Fet_temp_sensor_present     : %d\n",master_data.status5.BMS_Fet_temp_sensor_present);
            printf("BMS_ext_adc1_temp_sensor_present: %d\n",master_data.status5.BMS_ext_adc1_temp_sensor_present);
            printf("BMS_ext_adc2_temp_sensor_present: %d\n",master_data.status5.BMS_ext_adc2_temp_sensor_present);
            printf("BMS_afe_ts1_temp_sensor_present : %d\n",master_data.status5.BMS_afe_ts1_temp_sensor_present);
            printf("BMS_afe_ts3_temp_sensor_present : %d\n",master_data.status5.BMS_afe_ts3_temp_sensor_present);
            printf("BMS_gauge_temp_sensor_present   : %d\n",master_data.status5.BMS_gauge_temp_sensor_present);
            printf("\n\n");

            printf("BAT_gauge_SoC              :%hu\n",master_data.status6.BAT_gauge_SoC);
            printf("BAT_gaige_SoH              :%hu\n",master_data.status6.BAT_gaige_SoH);
            printf("BAT_gauge_cycleCount       :%hu\n",master_data.status6.BAT_gauge_cycleCount);
            printf("BAT_gauge_remainingCap_ro  :%hu\n",master_data.status6.BAT_gauge_remainingCap_ro);
            printf("BAT_gauge_remainingCap_phys:%f \n",master_data.status6.BAT_gauge_remainingCap_phys);
            printf("\n\n");

            printf("BAT_gauge_vPack_ro  : %u\n",master_data.status7.BAT_gauge_vPack_ro);
            printf("BAT_gauge_vPack_phys: %f\n",master_data.status7.BAT_gauge_vPack_phys);
            printf("BAT_gauge_iPack_ro  : %u\n",master_data.status7.BAT_gauge_iPack_ro);
            printf("BAT_gauge_iPack_phys: %f\n",master_data.status7.BAT_gauge_iPack_phys);
            printf("BAT_gauge_tPack_ro  : %u\n",master_data.status7.BAT_gauge_tPack_ro);
            printf("BAT_gauge_tPack_phys: %f\n",master_data.status7.BAT_gauge_tPack_phys);
            printf("\n");
           
            printf("Deserialized data successfully\n");
            printf("Received %d bytes\n", total_received);
            printf("\n");

        } else {
            printf("Received incomplete data: %d bytes\n", total_received);
        }
            printf("\n");
  }  
  
  return nClient;
}