/*
 * Imu_handler.c
 *
 *  Created on: May 23, 2025
 *      Author: kirtan
 */

#include "Imu_handler.h"
#include  "main.h"

extern TIM_HandleTypeDef htim2;


uint8_t accept[40];
int total_size = 0;
bool Imu_message = false;
uint16_t buffer_index = 0;
volatile uint32_t last_imu_time= 0;

EulerAngles angles;
EulerAngles last_angles;
EulerAngles txBuffer[MAX_MESSAGES];
uint8_t large_buffer[BUFFER_SIZE];


float bytesToFloat(uint8_t *bytes) {

    float value;
    memcpy(&value, bytes, sizeof(float));
    return value;
}

void Handleimumessage(uint32_t can_id, uint8_t *RxData){

    Imu_message = true;

	switch(can_id){

	        case 0x22:
	             int16_t roll_rad = (RxData[0]<<8 ) | RxData[1];
	             int16_t pitch_rad= (RxData[2]<<8)| RxData[3];
	             int16_t yaw_rad = (RxData[4]<<8 )| RxData[5];

	              if((roll_rad>=0 && roll_rad<=23040) ||(pitch_rad>=0 && pitch_rad<=23040) || (yaw_rad>=0 && yaw_rad<=23040)){

	             angles.roll= (roll_rad * 0.0078f);
	             angles.pitch= (pitch_rad * 0.0078f);
	             angles.yaw = (yaw_rad * 0.0078f);

	              }
	              else if((roll_rad>=42496 && roll_rad<=65536) ||(pitch_rad>=42496 && pitch_rad<=65536) || (yaw_rad>=42496 && yaw_rad<=65536)){

	             angles.roll= (roll_rad - 65536)*0.0078;
	             angles.pitch= (pitch_rad - 65536)*0.0078;
	             angles.yaw = (yaw_rad - 65536)*0.0078;

	              }
	             break;

	        case 0x34:
	             int16_t accX = (RxData[0] << 8) | RxData[1];
	             int16_t accY = (RxData[2] << 8) | RxData[3];
	             int16_t accZ = (RxData[4] << 8) | RxData[5];

	             angles.accx = accX * 0.0039;
	             angles.accy = accY * 0.0039;
	             angles.accz = accZ * 0.0039;

	             break;

			case 0x11:
			    angles.roll = bytesToFloat(&RxData[4]);
			    angles.pitch = bytesToFloat(&RxData[0]);
	            break;

		    case 0x12:
			    angles.yaw = bytesToFloat(&RxData[0]);
			    float ACCY= bytesToFloat(&RxData[4]);
			    angles.accy = ACCY * (-9.81);
			    break;

			case 0x13:
			    float ACCX=bytesToFloat(&RxData[0]);
			    angles.accx = ACCX * 9.81;
			    float ACCZ=bytesToFloat(&RxData[4]);
			    angles.accz = ACCZ * 9.81;
			    break;

	}

	angles.timestamp = HAL_GetTick();
    last_angles = angles;
}
void sendimudata(void) {

	uint32_t now = __HAL_TIM_GET_COUNTER(&htim2);
    if (Imu_message) {

        if (buffer_index < MAX_MESSAGES) {
            memcpy(&txBuffer[buffer_index], (void*)&last_angles, sizeof(EulerAngles));
            buffer_index++;
        }

        if (buffer_index >= MAX_MESSAGES) {
            total_size = buffer_index * sizeof(EulerAngles);
            memcpy(large_buffer, txBuffer, total_size);

        if (now - last_imu_time >= 1 && getSn_SR(TCP_SOCKET) == SOCK_ESTABLISHED) {
            int32_t sent = send(TCP_SOCKET, large_buffer, total_size);

        if (sent > 0) {
           	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0);
           	last_imu_time = now;
           	uint16_t rec = getSn_RX_RSR(TCP_SOCKET);
        if(rec >=2){
           	recv(TCP_SOCKET,accept,sizeof(accept));
           	}
           }
         }
            buffer_index = 0;
        }
            Imu_message = false;
    }

}
