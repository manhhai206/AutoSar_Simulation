#ifndef PWM_H
#define PWM_H

#include "Std_Types.h"

//Cấu hình cho PWM
typedef struct 
{
    uint8_t Pwm_Channel;    /**< Kênh PWM */
    uint16_t Pwm_Period;    /**< Chu kỳ PWM */
    uint16_t Pwm_DutyCycle; /**< Duty Cycle của PWM */
} PWM_ConfigType;

//Hàm khởi tạo PWM
void Pwm_Init(const PWM_ConfigType* ConfigPtr);

//Hàm thiết lập duty cycle
void Pwm_SetDutyCycle(uint8_t Channel, uint16_t DutyCycle);

#endif //PWM_H