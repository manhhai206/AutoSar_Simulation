#ifndef LOAD_SENSOR_H
#define LOAD_SENSOR_H

#include "Std_Types.h"

//Cấu hình cho cảm biến tải trọng (Load Sensor)
typedef struct 
{
    uint8_t LoadSensor_Channel;        /**<Kênh ADC đọc giá trị từ cảm biến */
    uint16_t LoadSensor_MaxValue;      /**< Gía trị tải trọng tối đa mà nó có thể đọc */
} LoadSensor_ConfigType;

//Khởi tạo cảm biến tải trọng 
Std_ReturnType LoadSensor_Init(const LoadSensor_ConfigType* ConfigPtr);

// Đọc giá trị cảm biến tải trọng
Std_ReturnType LoadSensor_Read(float *LoadValue);

#endif