#ifndef ADC_M_H
#define ADC_M_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <Std_Types.h>

//Cấu trúc chưa thông tin của cấu hình ADC
typedef struct 
{
    uint8_t Adc_Channel;        /**< Kênh ADC cần khởi tạo */
    uint32_t Adc_SamplingRate;  /**< Tần số lấy mẫu */
    uint32_t Adc_Resolution;    /**< Độ phân giải ADC */
} Adc_ConfigType;

//Hàm khởi tạo ADC
void Adc_Init(const Adc_ConfigType* ConfigPtr);

//Hàm đọc giá trị ADC
int Adc_ReadChannel(int channel, uint16_t* adc_Value);

// Hàm tạo độ trễ (delay)
void Delay(int milliseconds);


#endif