// PC emulated pins
//
// Outputs:
// DTR pin0
// RTS pin1
//
// Inputs:
// DSR pin2
// CTS pin3

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/time.h>
#include <stdint.h>

#include "Arduino.h"


extern void setup();
extern void loop();


unsigned long millis_start;
bool millis_started = false;


void millis_init() {
    timeval time;

    gettimeofday(&time, NULL);
    millis_start = (time.tv_sec * (uint64_t)1000) + (time.tv_usec / 1000);
    millis_started = true;
}

unsigned long millis() {
    timeval time;
    
    if (!millis_started) millis_init();
    
    gettimeofday(&time, NULL);
    uint64_t millis_now = (time.tv_sec * (uint64_t)1000) + (time.tv_usec / 1000);
    return millis_now - millis_start;
}


void pinMode(int pin, t_pinMode mode) {
    
}


void digitalWrite(int pin, int level) {
    switch (pin) {
    case 0:
        Serial1.setDTR(level);
        break;
    case 1:
        Serial1.setRTS(level);
        break;
    }
}


int  digitalRead(int pin) {
    switch (pin) {
    case 0:
        return Serial1.getDTR();
    case 1:
        return Serial1.getRTS();
    case 2:
        return Serial1.getDSR();
    case 3:
        return Serial1.getCTS();
    }
    return LOW;
}


void delay(unsigned long d) {
    while (d--) usleep(1000);
}



int main() {

    millis();

    setup();

    while(true) {
    	usleep(2);
    	loop();
    }

}
