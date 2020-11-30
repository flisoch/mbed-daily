#include "mbed.h"
 


// when button pressed, it "turns on" device and LED is on, when pressed again, it "turns off" device and LED blinks 3 times and eventually is off
int main_20_11_26()
{   
    DigitalIn button(USER_BUTTON);
    DigitalOut led(LED1);
    button.mode(PullDown);
    bool odd = false;

    while(1) {
        

        if (button == 0) { // Button is pressed
            odd = !odd; 
            if (!odd) {
                for (int i = 0; i < 4; ++i) {
                    led = !led;
                    ThisThread::sleep_for(200); // 200 ms
                }
                led = 0;
            } else {
                led = 1; // light
                ThisThread::sleep_for(200); // 200 ms
            }
            printf("Button state is: %d\n\r", button.read());
        }
    }
}

