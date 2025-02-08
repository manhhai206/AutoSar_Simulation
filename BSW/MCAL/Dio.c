#include "Dio.h"

//Khởi tạo DIO
void Dio_Init(void)
{
    //Khởi tạo số random ngẫu nhiên 
    srand(time(0));
    printf("Dio Intialized.\n");
}

//Đọc giá trị từ chân DIO
Dio_LevelType Dio_ReadChannel(int channel)
{
    Dio_LevelType dio_value;

    //Gọi hàm delay để mô phỏng thời gian đọc DIO
    Dio_Delay(200);

    //Giả lập trạng thái ngẫu nhiên 
    dio_value = (rand() %2 ) ? DIO_HIGH : DIO_LOW;

    //In ra trạng thái đọc từ kênh DIO
    printf("Reading DIO Channel %d: Value = %d\n", channel, dio_value);

    return dio_value;
}

//Ghi giá trị cho chân DIO
void Dio_WriteChannel(int channel, Dio_LevelType level)
{
    //Gọi hàm delay để mô phỏng thời gian ghi DIO
    Dio_Delay(100);

    //In ra trạng thái ghi vào chân DIO
    printf("Writing DIO Channel %d: Value  = %d\n", channel, level);
}

// Hàm delay để tạo độ trễ mô phỏng (tính theo milliseconds)
void Dio_Delay(int milliseconds) {
    usleep(milliseconds * 1000); // Hàm usleep tính theo micro giây, nhân với 1000 để thành mili giây
}