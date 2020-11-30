#include "my-lib.h"
#include <vector>

void blink_led(DigitalOut led, int count) {
    int sleep_millis = 100;
    for (int i=0; i < 2*count; ++i) {
        led = !led;  
        ThisThread::sleep_for(sleep_millis);
    }
}

void blink_led(DigitalOut led) {
    int sleep_millis = 100;
    led = !led;
    ThisThread::sleep_for(sleep_millis);
    led = !led;
}

bool matches(vector<int> v1, vector<int> v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }
    return true;
}