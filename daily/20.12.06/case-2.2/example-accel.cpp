#include "ThisThread.h"
#include "mbed.h"
#include "LSM6DS3.h"

LSM6DS3 accel(I2C_SDA, I2C_SCL, LSM6DS3_AG_I2C_ADDR(0));

int main()
{   
    // Initialize the gyro and accelerometer
    uint16_t status = accel.begin();
    printf("LSM6DS3 WHO_AM_I's returned: 0x%X\r\n", status);

    while (1) {
        accel.readAccel();
        printf("%7.3f, %7.3f, %7.3f \n\r", accel.ax, accel.ay, accel.az);
        ThisThread::sleep_for(500);
    }
}
