#ifndef  _IMU_HANDLER_H
#define  _IMU_HANDLER_H

#include <stdint.h>

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

int Imu_data_receive(int Client);

#endif