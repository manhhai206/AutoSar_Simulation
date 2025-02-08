#include "Pwm.h"
#include <stdio.h>

//Hàm khởi tạo PWM
void Pwm_Init(const PWM_ConfigType* ConfigPtr)
{
    printf("PWM Initialized for Channel %d with Period %d ms and DutyCycle %d\n",
        ConfigPtr->Pwm_Channel,ConfigPtr->Pwm_Period,ConfigPtr->Pwm_DutyCycle);
}

//Hàm thiết lập duty cycle
void Pwm_SetDutyCycle(uint8_t Channel, uint16_t DutyCycle)
{
    printf("Pwm Channel %d set to Duty Cycle: %d\n",Channel,DutyCycle);
}