#include "ThisThread.h"
#include "mbed.h"
#include "OPT3001.h"

DigitalOut led(LED1);
OPT3001 sensor_opt(I2C_SDA, I2C_SCL);

int main_20_12_06_2()
{
    printf("Hello, opt3001!\n\r");
    while(1) {
        ThisThread::sleep_for(1000); // 1 second
        led = !led; // Toggle LED
        printf("%d lux\r\n", sensor_opt.readSensor());
    }
}