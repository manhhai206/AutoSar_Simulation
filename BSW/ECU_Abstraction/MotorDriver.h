#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include "Std_Types.h"

//Cấu trúc cấu hình cho motor
typedef struct{
    uint8_t Motor_Channel;      /**< Kênh PWM điều khiển motor */
    uint16_t Motor_MaxTorque;   /**< Mô men xoắn tối đa */
} MotorDriver_ConfigType;

//Khởi tạo mô tơ
Std_ReturnType MotorDriver_Init(const MotorDriver_ConfigType* ConfigPtr);

// Điều chính mô men xoắn
Std_ReturnType MotorDriver_SetTorque(float TorqueValue);

#endif