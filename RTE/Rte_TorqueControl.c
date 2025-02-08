#include "Rte_TorqueControl.h"
#include "ThrottleSensor.h"  // API  để đọc cảm biến bàn đạp ga
#include "SpeedSensor.h"     // API  để đọc cảm biến tốc độ
#include "LoadSensor.h"      // API  để đọc cảm biến tải trọng
#include "TorqueSensor.h"    // API để đọc mô-men xoắn thực tế
#include "MotorDriver.h"     // API để điều khiển mô-men xoắn động cơ
#include "Std_Types.h"

// API để đọc dữ liệu từ cảm biến bàn đạp ga
Std_ReturnType Rte_Read_RpThrottleSensor_ThrottlePosition(float* ThrottlePosition) {
    if (ThrottlePosition == NULL) {
        return E_NOT_OK;  // Trả về lỗi nếu con trỏ NULL
    }
    return ThrottleSensor_Read(ThrottlePosition);  // Gọi API để đọc giá trị từ cảm biến
}

// API để đọc dữ liệu từ cảm biến tốc độ
Std_ReturnType Rte_Read_RpSpeedSensor_Speed(float* Speed) {
    if (Speed == NULL) {
        return E_NOT_OK;
    }
    return SpeedSensor_Read(Speed);  // Gọi APIđể đọc giá trị từ cảm biến tốc độ
}

// API để đọc dữ liệu từ cảm biến tải trọng
Std_ReturnType Rte_Read_RpLoadSensor_LoadWeight(float* LoadWeight) {
    if (LoadWeight == NULL) {
        return E_NOT_OK;
    }
    return LoadSensor_Read(LoadWeight);  // Gọi API để đọc giá trị từ cảm biến tải trọng
}

// API để đọc mô-men xoắn thực tế từ cảm biến mô-men xoắn
Std_ReturnType Rte_Read_RpTorqueSensor_ActualTorque(float* ActualTorque) {
    if (ActualTorque == NULL) {
        return E_NOT_OK;
    }
    return TorqueSensor_Read(ActualTorque);  // Gọi API để đọc mô-men xoắn thực tế
}

// API để ghi dữ liệu mô-men xoắn yêu cầu tới bộ điều khiển động cơ
Std_ReturnType Rte_Write_PpMotorDriver_SetTorque(float TorqueValue) {
    return MotorDriver_SetTorque(TorqueValue);  // Gọi API  để ghi mô-men xoắn yêu cầu tới động cơ
}

// API khởi tạo cảm biến bàn đạp ga
Std_ReturnType Rte_Call_RpThrottleSensor_Init(void) {
    ThrottleSensor_ConfigType throttleSensorConfig = {
        .ThrottleSensor_Channel = 0  // Kênh ADC cho cảm biến bàn đạp ga
    };
    return ThrottleSensor_Init(&throttleSensorConfig);  // Gọi API  để khởi tạo cảm biến bàn đạp ga
}

// API khởi tạo cảm biến tốc độ
Std_ReturnType Rte_Call_RpSpeedSensor_Init(void) {
    // Cấu hình cho cảm biến tốc độ
    SpeedSensor_ConfigType speedSensorConfig = {
        .SpeedSensor_Channel = 1,        // Kênh ADC cho cảm biến tốc độ
        .SpeedSensor_MaxValue = 200      // Tốc độ tối đa giả lập (200 km/h)
    };
    return SpeedSensor_Init(&speedSensorConfig);  // Gọi API để khởi tạo cảm biến tốc độ
}

// API khởi tạo cảm biến tải trọng
Std_ReturnType Rte_Call_RpLoadSensor_Init(void) {
    // Cấu hình cho cảm biến tải trọng
    LoadSensor_ConfigType loadSensorConfig = {
        .LoadSensor_Channel = 2,         // Kênh ADC cho cảm biến tải trọng
        .LoadSensor_MaxValue = 1000      // Tải trọng tối đa giả lập (1000 kg)
    };
    return LoadSensor_Init(&loadSensorConfig);  // Gọi API để khởi tạo cảm biến tải trọng
}

// API khởi tạo cảm biến mô-men xoắn
Std_ReturnType Rte_Call_RpTorqueSensor_Init(void) {
    // Cấu hình cho cảm biến mô-men xoắn
    TorqueSensor_ConfigType torqueSensorConfig = {
        .TorqueSensor_Channel = 3,       // Kênh ADC cho cảm biến mô-men xoắn
        .TorqueSensor_MaxValue = 500     // Mô-men xoắn tối đa giả lập (500 Nm)
    };
    return TorqueSensor_Init(&torqueSensorConfig);  // Gọi API để khởi tạo cảm biến mô-men xoắn
}

// API khởi tạo bộ điều khiển mô-men xoắn
Std_ReturnType Rte_Call_PpMotorDriver_Init(void) {
    // Cấu hình cho bộ điều khiển mô-men xoắn
    MotorDriver_ConfigType motorDriverConfig = {
        .Motor_Channel = 1,              // Kênh điều khiển mô-tơ
        .Motor_MaxTorque = 300           // Mô-men xoắn tối đa giả lập (300 Nm)
    };
    return MotorDriver_Init(&motorDriverConfig);  // Gọi API để khởi tạo bộ điều khiển mô-men xoắn
}