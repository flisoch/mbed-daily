#include "ThisThread.h"
#include "mbed.h"
#include "LSM6DS3.h"
#include "OPT3001.h"
#include "BME280.h"

LSM6DS3 accel(I2C_SDA, I2C_SCL, LSM6DS3_AG_I2C_ADDR(0));
OPT3001 sensor_opt(I2C_SDA, I2C_SCL);
BME280 sensor_bme(I2C_SDA, I2C_SCL);

int main()
{
    // Initialize the gyro and accelerometer
    uint16_t status = accel.begin();
    printf("LSM6DS3 WHO_AM_I's returned: 0x%X\r\n", status);

    while (1) {
        accel.readAccel();
        printf("%7.3f, %7.3f, %7.3f \n\r", accel.ax, accel.ay, accel.az);
        printf("%d lux\r\n", sensor_opt.readSensor());
        printf("%2.2f degC, %04.2f hPa, %2.2f %%\r\n\n\n", sensor_bme.getTemperature(), sensor_bme.getPressure(), sensor_bme.getHumidity());
        ThisThread::sleep_for(2000);
    }
}
