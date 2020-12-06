#include "mbed.h"
#include <vector>
#include "my-lib.h"
 
// 3-digit password input imitation with 1 button. Long press(5 iters) to start inserting new digit, short press to increase current digit. If led is on in the end, you enetered password correctly



int main()
{   
    DigitalIn button(BUTTON1, PullDown);
    DigitalOut led(LED1);
    Timer timer;
    int timeBeforePress;
    enum State {ready, first, second, third, win, fail};
    enum PrevIterButtonState {pressed, unpressed};

    State state = ready;
    PrevIterButtonState prevIterButtonState = unpressed;
    int itersWhilePressed = 0;
    int iter_sleep = 100;
    vector<int> correct_code = { 2, 3, 3 }; 
    vector<int> actual_code = {0, 0, 0}; 

    timer.start();


    while (1) {
        switch (state) {
            case State::ready: 
                if (button != 0) {
                itersWhilePressed = 0; 
                }
                else {
                itersWhilePressed++;

                    if (itersWhilePressed > 5) {
                        printf("Switch to first digit input\n");
                        state = State::first;
                        itersWhilePressed = 0;
                        prevIterButtonState = PrevIterButtonState::unpressed;
                        blink_led(led, 5);
                    }
                }
                ThisThread::sleep_for(iter_sleep);
                break;
            case State::first:
                if (button != 0) {
                    if (prevIterButtonState == PrevIterButtonState::pressed) {
                        actual_code[0] += 1;
                        printf("Total counts: %d\n", actual_code[0]);
                        blink_led(led);
                    }
                    itersWhilePressed = 0;
                    prevIterButtonState = PrevIterButtonState::unpressed;
                }
                else {
                    itersWhilePressed++;
                    prevIterButtonState = PrevIterButtonState::pressed;
                    if (itersWhilePressed == 5) {
                        printf("Switch to second digit input\n");
                        state = State::second;
                        itersWhilePressed = 0;
                        prevIterButtonState = PrevIterButtonState::unpressed;
                        blink_led(led, 3);
                        led = 0;
                    }
                }
                ThisThread::sleep_for(iter_sleep);
                break;
            case State::second:
                if (button != 0) {
                    if (prevIterButtonState == PrevIterButtonState::pressed) {
                        actual_code[1] += 1;
                        printf("Total counts: %d\n", actual_code[1]);
                        blink_led(led);
                    }
                    itersWhilePressed = 0;
                    prevIterButtonState = PrevIterButtonState::unpressed;

                }
                else {
                    itersWhilePressed++;
                    prevIterButtonState = PrevIterButtonState::pressed;
                    if (itersWhilePressed == 5) {
                        printf("Switch to third digit input\n");
                        state = State::third;
                        itersWhilePressed = 0;
                        prevIterButtonState = PrevIterButtonState::unpressed;
                        blink_led(led, 3);
                        led = 0;
                    }
                }
                ThisThread::sleep_for(iter_sleep);
                break;
            case State::third:
                if (button != 0) {
                    if (prevIterButtonState == PrevIterButtonState::pressed) {
                        actual_code[2] += 1;
                        printf("Total counts: %d\n", actual_code[2]);
                        blink_led(led);
                    }
                    itersWhilePressed = 0;
                    prevIterButtonState = PrevIterButtonState::unpressed;

                }
                else {
                    itersWhilePressed++;
                    prevIterButtonState = PrevIterButtonState::pressed;

                    if (itersWhilePressed == 5) {
                        bool correct = matches(correct_code, actual_code);
                        blink_led(led, 7);
                        if (correct) {
                            printf("Welcome!\n");
                            state = State::win;
                            led = 1;
                        }
                        else {
                            printf("Wrong password!\n");
                            state = State::fail;
                            led = 0;
                        }
                        itersWhilePressed = 0;
                        prevIterButtonState = PrevIterButtonState::unpressed;
                        actual_code = {0,0,0};                        
                    }
                ThisThread::sleep_for(iter_sleep);
                break;
            case State::win:
                if (button != 0) {
                    itersWhilePressed = 0;
                }
                else {
                    itersWhilePressed++;
                    if (itersWhilePressed == 5) {
                        printf("Switch to Ready state\n");
                        state = State::ready;
                        itersWhilePressed = 0;
                        prevIterButtonState = PrevIterButtonState::unpressed;
                        blink_led(led, 3);
                        led = 0;
                    }
                }
                ThisThread::sleep_for(iter_sleep);
                break;
            case State::fail:
                if (button != 0) {
                    itersWhilePressed = 0;
                }
                else {
                    itersWhilePressed++;
                    if (itersWhilePressed == 5) {
                        printf("Switch to Ready state\n");
                        state = State::ready;
                        itersWhilePressed = 0;
                        prevIterButtonState = PrevIterButtonState::unpressed;
                        blink_led(led, 3);
                        led = 0;
                    }
                }
                ThisThread::sleep_for(iter_sleep);
                break;
            }
        }
    }
}
        