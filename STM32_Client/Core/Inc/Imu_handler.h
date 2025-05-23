/*
 * Imu_handler.h
 *
 *  Created on: May 23, 2025
 *      Author: kirtan
 */

#ifndef INC_IMU_HANDLER_H_
#define INC_IMU_HANDLER_H_

#include <main.h>

extern bool Imu_message;
extern int total_size ;

typedef struct {

    float roll;
    float pitch;
    float yaw;
    float accx;
    float accy;
    float accz;
    uint32_t timestamp;

} EulerAngles;

extern EulerAngles angles;
extern EulerAngles last_angles;
extern EulerAngles txBuffer[MAX_MESSAGES];
extern uint8_t large_buffer[BUFFER_SIZE];

void sendimudata(void);
float bytesToFloat(uint8_t *bytes);
void Handleimumessage(uint32_t can_id,uint8_t *RxData);

#endif /* INC_IMU_HANDLER_H_ */
