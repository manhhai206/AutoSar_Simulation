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

// Hàm cập nhật hệ thống điều khiển mô-men xoắn
void TorqueControl_Update(void) {
    float throttle_input = 0.0f;
    float current_speed = 0.0f;
    float load_weight = 0.0f;
    float actual_torque = 0.0f;
    float desired_torque = 0.0f;

    // Đọc dữ liệu từ cảm biến bàn đạp ga
    if (Rte_Read_RpThrottleSensor_ThrottlePosition(&throttle_input) == E_OK) {
        printf("Throttle position value: %.2f%%\n", throttle_input * 100);
    } else {
        printf("Error reading throttle sensor!\n");
    }

    // Đọc dữ liệu từ cảm biến tốc độ
    if (Rte_Read_RpSpeedSensor_Speed(&current_speed) == E_OK) {
        printf("Current vehicle speed: %.2f km/h\n", current_speed);
    } else {
        printf("Error reading speed sensor!\n");
    }

    // Đọc dữ liệu từ cảm biến tải trọng
    if (Rte_Read_RpLoadSensor_LoadWeight(&load_weight) == E_OK) {
        printf("Current load weight: %.2f kg\n", load_weight);
    } else {
        printf("Error reading load sensor!\n");
    }

    // Tính toán mô-men xoắn yêu cầu
    desired_torque = throttle_input * MAX_TORQUE;
    if (current_speed > 50.0f) {
        desired_torque *= 0.8f;  // Decrease torque if speed is high
    }
    if (load_weight > 500.0f) {
        desired_torque += 10.0f;  // Increase torque if load weight is high
    }

    // Giới hạn mô-men xoắn trong phạm vi an toàn
    if (desired_torque > MAX_TORQUE) {
        desired_torque = MAX_TORQUE;
    } else if (desired_torque < MIN_TORQUE) {
        desired_torque = MIN_TORQUE;
    }

    // In ra mô-men xoắn yêu cầu
    printf("Desired torque: %.2f Nm\n", desired_torque);

    // Ghi mô-men xoắn yêu cầu tới bộ điều khiển động cơ
    if (Rte_Write_PpMotorDriver_SetTorque(desired_torque) == E_OK) {
        printf("Desired torque sent to motor.\n");
    } else {
        printf("Error sending torque to motor!\n");
    }

    // Đọc mô-men xoắn thực tế để so sánh với mô-men xoắn yêu cầu
    if (Rte_Read_RpTorqueSensor_ActualTorque(&actual_torque) == E_OK) {
        printf("Actual torque: %.2f Nm\n", actual_torque);
    } else {
        printf("Error reading actual torque!\n");
    }

    // So sánh và điều chỉnh nếu có sự sai lệch giữa mô-men xoắn thực tế và yêu cầu
    if (actual_torque < desired_torque) {
        printf("Increase torque to reach desired level.\n");
    } else if (actual_torque > desired_torque) {
        printf("Decrease torque to reach desired level.\n");
    }
}
