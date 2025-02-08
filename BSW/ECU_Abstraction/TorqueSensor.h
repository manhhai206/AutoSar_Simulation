#ifndef TORQUESENSOR_H
#define TORQUESENSOR_H

#include "Std_Types.h"

// Cấu hình cho cảm biến mô-men xoắn
typedef struct 
{
    uint8_t TorqueSensor_Channel;       /**< Kênh ADC để đọc giá trị từ cảm biến moment xoắn */
    uint16_t TorqueSensor_MaxValue;     /**< Gía trị mô-men xoắn tối đa (Nm) */
} TorqueSensor_ConfigType;

// Hàm khởi tạo cho mô men xoắn
Std_ReturnType TorqueSensor_Init(const TorqueSensor_ConfigType *ConfigPtr);

// Đọc giá trị từ cảm biến mo men xoắn
Std_ReturnType TorqueSensor_Read(float* TorqueValue);


#endif //TORQUESENSOR_H