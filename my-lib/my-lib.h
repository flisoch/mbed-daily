#include "mbed.h"

#ifndef ADD_HEADER
#define ADD_HEADER
void blink_led(DigitalOut led, int count);

void blink_led(DigitalOut led);

bool matches(vector<int> v1, vector<int> v2);
#endif