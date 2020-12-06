#include "mbed.h"
// Long press feature

int main()
{   
    DigitalIn button(BUTTON1, PullDown);
    DigitalOut led(LED1);
    Timer timer;
    int timeBeforePress;
    enum State {idle, ready};

    timer.start();
    State state = idle;

    while (1) {

        if (button != 0) {
        timeBeforePress = timer.read(); 
        }
        else {
            if (timer.read() - timeBeforePress < 2) {
                printf("holding\n");
            }else {
                printf("held > 2 seconds\n");
                state = State::ready;
            }
        }

        ThisThread::sleep_for(20);
    }

}

