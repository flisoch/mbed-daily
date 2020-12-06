#include "mbed.h"
#include "my-lib.h"
 
// password input imitation with 1 button. Long press to start inserting new digit, short press to increase current digit. In this version there is no counting yet.


int main()
{   
    DigitalIn button(BUTTON1, PullDown);
    DigitalOut led(LED1);
    Timer timer;
    int timeBeforePress;
    enum State {ready, first, second, third, win, fail};

    timer.start();
    State state = ready;
    int iter_sleep = 70;

    while (1) {
        switch (state) {
            case State::ready: 
                if (button != 0) {
                timeBeforePress = timer.read(); 
                }
                else {
                    if (timer.read() - timeBeforePress > 2) {
                        printf("Switch to first digit input\n");
                        state = State::first;
                        blink_led(led, 3);
                        // led = 1;
                    }
                }
                ThisThread::sleep_for(iter_sleep);
                break;
            case State::first:
                if (button != 0) {
                timeBeforePress = timer.read(); 
                }
                else {
                    if (timer.read() - timeBeforePress < 2) {
                        printf("Press counted\n");
                        printf("Total counts: X\n");
                        blink_led(led);
                    }else {
                        printf("Switch to second digit input\n");
                        state = State::second;
                        blink_led(led, 3);
                        led = 1;
                    }
                }
                ThisThread::sleep_for(iter_sleep);
                break;
            case State::second:
                if (button != 0) {
                timeBeforePress = timer.read(); 
                }
                else {
                    if (timer.read() - timeBeforePress < 2) {
                        printf("Press counted\n");
                        printf("Total counts: X\n");
                        blink_led(led);
                    }else {
                        printf("Switch to third digit input\n");
                        state = State::third;
                        blink_led(led, 3);
                        led = 1;
                    }
                }
                ThisThread::sleep_for(iter_sleep);
                break;
            case State::third:
                if (timer.read() - timeBeforePress < 2) {
                        printf("Press counted\n");
                        printf("Total counts: X\n");
                        blink_led(led);
                    }else {
                        bool correct = true;
                        if (correct) {
                            printf("Welcome!\n");
                            state = State::win;
                        }
                        else {
                            printf("Wrong password!\n");
                            state = State::fail;
                        }
                        blink_led(led, 3);
                        led = 1;
                    }
                break;
            case State::win:
                break;
            case State::fail:
                break;
        }
        
    }

}

