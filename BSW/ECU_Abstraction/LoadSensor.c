#include <stdio.h>
#include "LoadSensor.h"
#include "Adc_M.h"

//Gỉa lập cấu hình của cảm biến tải trọng
static LoadSensor_ConfigType LoadSensor_CurrentConfig;

//Khởi tạo cảm biến tải trọng 
Std_ReturnType LoadSensor_Init(const LoadSensor_ConfigType* ConfigPtr)
{
    if(ConfigPtr == NULL)
    {
        printf("Error: Null configuration pointer passed to LoadSensor_Init.\n");
        return E_NOT_OK;
    }

    // Lưu cấu hình
    LoadSensor_CurrentConfig.LoadSensor_Channel =  ConfigPtr->LoadSensor_Channel;
    LoadSensor_CurrentConfig.LoadSensor_MaxValue =  ConfigPtr->LoadSensor_MaxValue;

    Adc_ConfigType adc_config;
    adc_config.Adc_Channel = LoadSensor_CurrentConfig.LoadSensor_Channel;
    Adc_Init(&adc_config);

    // In ra thông tin cấu hình cảm biến tải trọng
    printf("Load Sensor Initialized with Configuration:\n");
    printf(" - ADC Channel: %d\n", LoadSensor_CurrentConfig.LoadSensor_Channel);
    printf(" - Max Load Value: %d kg\n", LoadSensor_CurrentConfig.LoadSensor_MaxValue);
    return E_OK;
}

// Đọc giá trị cảm biến tải trọng
Std_ReturnType LoadSensor_Read(float *LoadValue)
{
    if(LoadValue == NULL)
    {
        printf("Error: Failed to read ADC value.\n");
        return E_NOT_OK;
    }

    // Đọc giá trị ADC từ MCAL
    uint16_t adcValue = 0;
    if (Adc_ReadChannel(LoadSensor_CurrentConfig.LoadSensor_Channel, &adcValue) != E_OK) {
        printf("Error: Failed to read ADC value.\n");
        return E_NOT_OK;
    }

    //Chuyển đổi giá trị ADC sang mô men xoắn 
    *LoadValue = ((float)adcValue / 1023.0f) * LoadSensor_CurrentConfig.LoadSensor_MaxValue;

    // In ra giá trị tải trọng
    printf("Load Sensor (ADC Channel %d): Load = %.2f kg\n",
            LoadSensor_CurrentConfig.LoadSensor_Channel, *LoadValue);
            
    return E_OK;
}