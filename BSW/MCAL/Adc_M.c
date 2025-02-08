#include "Adc_M.h"
#include <stddef.h> //Định nghĩa NULL

static Adc_ConfigType Adc_CurrentConfig; /**< Lưu trữ cấu hình hiện tại của ADC */

//Hàm khởi tạo ADC
void Adc_Init(const Adc_ConfigType* ConfigPtr)
{
    if(ConfigPtr == NULL)
    {
        printf("Error: Null configuration pointer passed to Adc_Init.\n");
        return;
    }

    //Lưu cấu hình Adc từ ConfigPtr vào biến static
    Adc_CurrentConfig.Adc_Channel =  ConfigPtr->Adc_Channel;
    Adc_CurrentConfig.Adc_Resolution =  ConfigPtr->Adc_Resolution;
    Adc_CurrentConfig.Adc_SamplingRate =  ConfigPtr->Adc_SamplingRate;

    srand(time(0));

    printf("Adc Initialized with Configuration: \n");
    printf(" - Channel: %d\n", Adc_CurrentConfig.Adc_Channel);
    printf(" - Resolution: %d Hz\n", Adc_CurrentConfig.Adc_Resolution);
    printf(" - SamplingRate: %d-bit\n", Adc_CurrentConfig.Adc_SamplingRate);

}

//Hàm đọc giá trị ADC
int Adc_ReadChannel(int channel, uint16_t* adc_Value)\
{
    uint16_t adc_value = 0;

    // Tạo độ trễ 500ms để mô phỏng
    Delay(500);

    // Giả lập giá trị ngẫu nhiên từ 0 đến 1023 (giá trị ADC 10-bit)
    adc_value =  rand() % 1024;

    //In ra giá trị từ kênh ADC
    printf("Reading ADC Channel %d: Value = %d\n",channel,adc_value);

    // Trả giá trị đọc được thông qua tham chiếu
    *adc_Value = adc_value;

    return E_OK;  // Trả về E_OK nếu đọc thành công
}

// Hàm delay để tạo độ trễ mô phỏng (tính theo milliseconds)
void Delay(int milliseconds) {
    usleep(milliseconds * 1000); // Hàm usleep tính theo micro giây, nhân với 1000 để thành mili giây
}