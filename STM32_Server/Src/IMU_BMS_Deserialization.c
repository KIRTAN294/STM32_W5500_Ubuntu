#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <errno.h>
#include <sched.h>
#include "bms_can-config.h"
#include "bms_can.h"
#include "dbccodeconf.h"

#define MAX_MESSAGES (28/ sizeof(EulerAngles))
unsigned char buffer[28] = {0};
int total_received = 0;


#define Send_IMU_Data 1
#define Send_BMS_Data 2

typedef uint8_t Commandtype;

typedef struct{

  uint32_t can_id;
  uint32_t length;
  uint32_t payload[12];

}Ethernet_BMS_Packet;

Ethernet_BMS_Packet eth_msg;

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

Struct_A master_data;
#define TOTAL_SIZE  sizeof(Ethernet_BMS_Packet)
char Buffer[TOTAL_SIZE];

typedef struct {

    float roll;
    float pitch;
    float yaw;
    float accx;
    float accy;
    float accz;
    uint32_t timestamp;
    
} EulerAngles;
  EulerAngles angles;
  EulerAngles txBuffer[MAX_MESSAGES];

void error(const char *msg) {
    perror(msg);  
    exit(1);
}

int main(int argc, char *argv[]) {

    int server_fd,nRet;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);

     server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        error("ERROR opening socket\n");
    }
   
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(6565); 

    memset(&(address.sin_zero),0,8);

  if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        error("ERROR on binding\n");
    }
    nRet = listen(server_fd,5);
      if (nRet < 0)
      {
      error("\nCan't listen at port");
      return -1;
      }
  int nClient = 0;
    nClient = accept(server_fd,(struct sockaddr*)&address,&addrlen);
      if (nClient < 0)
      {
      error("\nCan't listen at port");
      return -1;
      }

  int nodelay = 1;
  setsockopt(nClient, IPPROTO_TCP, TCP_NODELAY, (char*)&nodelay, sizeof(nodelay));

  int choice;
    printf("Enter command:\n");
    printf("1 - Request IMU Data\n");
    printf("2 - Request BMS Data\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    
    if (choice != Send_IMU_Data && choice != Send_BMS_Data) {
        printf("Invalid choice.\n");
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
    while (1){
           printf("Running on CPU %d\n", sched_getcpu());
      nRet = recv(nClient, buffer+total_received, sizeof(buffer)-total_received, 0);
      if (nRet == 0) {
          printf("Connection closed by client\n");
          break;
          }
          if (nRet < 0) {
            error("Receive  error:");
              break;
          }    
      if (nRet > 0) {
          total_received += nRet;
          send(nClient, "OK", 2, 0);
          int complete_messages = total_received / sizeof(EulerAngles);

      for (int i = 0; i < complete_messages; i++) {
      
      memcpy(&angles, buffer + (i * sizeof(EulerAngles)), sizeof(EulerAngles));

      printf("TimeStamp: %u, Roll: %.2f, Pitch: %.2f, Yaw: %.2f, AccX: %.2f, AccY: %.2f, AccZ: %.2f \r\n",
          angles.timestamp, angles.roll, angles.pitch, angles.yaw,
          angles.accx, angles.accy, angles.accz);
      }
      if (nRet < 0)
      {
      error("\nCan't recv message:");
        return -1;
      }
      if (complete_messages > 0) {
      int remaining = total_received - (complete_messages * sizeof(EulerAngles));
      if (remaining > 0) {
          memmove(buffer, buffer + (complete_messages * sizeof(EulerAngles)), remaining);
      }
      total_received = remaining;
      }
    }
  }
}
else if( choice == Send_BMS_Data) {

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
              if (nRet < 0) {
               printf("Receive  error:");
               break;
              }
               continue;
            }  
         total_received += nRet;     
    }
    if (total_received >= TOTAL_SIZE) {

      switch(eth_msg.can_id){
               
         case 0x110:
            memcpy(&master_data.status, eth_msg.payload, sizeof(master_data.status));
            break;

        case BAT_BMS_IntTemp_CANID:
            memcpy(&master_data.status1, eth_msg.payload,sizeof(master_data.status1));
            break;

        case BAT_BMS_ExtTemp_CANID:
            memcpy(&master_data.status2, eth_msg.payload, sizeof(master_data.status2));
            break;

        case 0x1FF310:
            memcpy(&master_data.status3, eth_msg.payload, sizeof(master_data.status3));
            break;

        case 0x1FF615:
            memcpy(&master_data.status4, eth_msg.payload, sizeof(master_data.status4));
            break;

        case 0x1FF110:
            memcpy(&master_data.status5, eth_msg.payload, sizeof(master_data.status5));
            break;

        case 0x1FF810:
            memcpy(&master_data.status6, eth_msg.payload, sizeof(master_data.status6));
            break;

        case 0x1FF820:
            memcpy(&master_data.status7, eth_msg.payload, sizeof(master_data.status7));
            break;

        default:
            printf("Wrong ID:%u",eth_msg.can_id);
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
}
}
close(nClient);
close(server_fd);
return 0;
}


