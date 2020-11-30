#include "mbed.h"

 
// when button pressed, timer starts counting how much time it takes to toggle the led and print message and "unpresses" button

int main_20_11_27()
{
    DigitalIn button(BUTTON1, PullDown);
    DigitalOut led(LED1);
    Timer timer;
    int start, finish, start1, finish1;
    bool stop = true;

    while (1) {
        if (!stop) {
            timer.start();
            start = timer.read_us();
            led = !led;
            finish = timer.read_us();
            start1 = timer.read_us();
            printf("Toggle the led takes %d us\n", finish - start);
            finish1 = timer.read_us();
            printf("Print previous message took %d us\n", finish1 - start1);
            stop = !stop;
            ThisThread::sleep_for(200); // 200 ms
        }
        if (button == 0) {
            stop = !stop;
        }

    }
}

