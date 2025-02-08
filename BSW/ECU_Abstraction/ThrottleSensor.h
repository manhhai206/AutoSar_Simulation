#ifndef THROTTLESENSOR_H
#define THROTTLESENSOR_H

#include "Std_Types.h"

// Cấu hình cho cảm biến bàn đạp ga
typedef struct {
    uint8_t ThrottleSensor_Channel;  // Kênh ADC để đọc giá trị từ cảm biến bàn đạp ga
} ThrottleSensor_ConfigType;

// Prototype cho hàm khởi tạo cảm biến bàn đạp ga
Std_ReturnType ThrottleSensor_Init(const ThrottleSensor_ConfigType* ConfigPtr);

// Prototype cho hàm đọc giá trị từ cảm biến bàn đạp ga
Std_ReturnType ThrottleSensor_Read(float* ThrottlePosition);

#endif 
