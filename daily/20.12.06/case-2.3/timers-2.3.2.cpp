#include "DigitalOut.h"
#include "mbed.h"



void toggle_led(DigitalOut led1)
{
    led1 = !led1;
}

int main()
{
    Ticker toggle_led_ticker;
    DigitalOut led1(LED1);
    // Init the ticker with the address of the function (toggle_led) to be           attached and the interval (100 ms)
    toggle_led_ticker.attach(&toggle_led, 0.1);
    while (true) {
        // Do other things...
    }
}