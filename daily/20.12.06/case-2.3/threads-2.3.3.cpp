#include "Thread.h"
#include "mbed.h"

void print_char(char c = '*')
{
    printf("%c", c);
    fflush(stdout);
}

Thread thread1;
Thread thread2;

DigitalOut led1(LED1);

void led_thread() {
    while (true) {
        led1 = !led1;
        ThisThread::sleep_for(500);
    }
}
void print_thread()
{
    while (true) {
        ThisThread::sleep_for(1000);
        print_char();
    }
}

int main()
{
    printf("\n\n*** RTOS basic example ***\n");
    thread1.start(print_thread);
    thread2.start(led_thread);
   
}