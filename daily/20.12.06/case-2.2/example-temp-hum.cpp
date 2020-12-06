#include "ThisThread.h"
#include "mbed.h"
#include "BME280.h"


DigitalOut led(LED1);
BME280 sensor_bme(I2C_SDA, I2C_SCL);

int main()
{    
    printf("Hello, bme280!\n\r");
    while(1) {
        ThisThread::sleep_for(1000); // 1 second
        led = !led; // Toggle LED
        printf("%2.2f degC, %04.2f hPa, %2.2f %%\r\n", sensor_bme.getTemperature(), sensor_bme.getPressure(), sensor_bme.getHumidity());
    }
}