#ifndef DIO_H
#define DIO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>   /**<Sử dụng cho random */
#include <unistd.h> /**< Sử dụng cho delay */

// Trạng thái DIO
typedef enum
{
    DIO_LOW = 0,    /**<Trạng thái thấp(0V) */
    DIO_HIGH = 1    /**<Trạng thái cao(5V) */
} Dio_LevelType;

//Khởi tạo DIO
void Dio_Init(void);

//Đọc giá trị từ chân DIO
Dio_LevelType Dio_ReadChannel(int channel);

//Ghi vào chân DIO
void Dio_WriteChannel(int channel, Dio_LevelType level);

//Hàm tạo độ trễ
void Dio_Delay(int miliseconds);

#endif //DIO_H