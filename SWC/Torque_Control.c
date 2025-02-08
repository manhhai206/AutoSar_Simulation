#include "Rte_TorqueControl.h"
#include "Torque_Control.h"
#include <stdio.h>

// Hàm khởi tạo hệ thống điều khiển mô-men xoắn
void TorqueControl_Init(void) {
    // Khởi tạo các cảm biến bàn đạp ga, tốc độ và tải trọng
    Std_ReturnType status;

    printf("Utilized Torque Control system...\n");

    // Khởi tạo cảm biến bàn đạp ga
    status = Rte_Call_RpThrottleSensor_Init();
    if (status == E_OK) {
        printf("Throttle sensor initialized successfully.\n");
    } else {
        printf("Error initializing throttle sensor.\n");
        return;
    }

    // Khởi tạo cảm biến tốc độ
    status = Rte_Call_RpSpeedSensor_Init();
    if (status == E_OK) {
        printf("Speed sensor initialized successfully.\n");
    } else {
        printf("Error initializing speed sensor.\n");
        return;
    }

    // Khởi tạo cảm biến tải trọng
    status = Rte_Call_RpLoadSensor_Init();
    if (status == E_OK) {
        printf("Load sensor initialized successfully.\n");
    } else {
        printf("Error initializing load sensor.\n");
        return;
    }

    // Khởi tạo cảm biến mô-men xoắn thực tế
    status = Rte_Call_RpTorqueSensor_Init();
    if (status == E_OK) {
        printf("Actual torque sensor initialized successfully.\n");
    } else {
        printf("Error initializing torque sensor.\n");
        return;
    }

    // Khởi tạo bộ điều khiển mô-men xoắn (có thể là PWM hoặc module điều khiển động cơ)
    status = Rte_Call_PpMotorDriver_Init();
    if (status == E_OK) {
        printf("Torque controller initialized successfully.\n");
    } else {
        printf("Error initializing torque controller.\n");
        return;
    }

    printf("Torque Control system is ready.\n");
}


