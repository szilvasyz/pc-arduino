//
// Arduino-style program body
//
//
// Serial: local console
// Serial1: configured serial port
//
// PC emulated pins
//
// Outputs:
// DTR pin0
// RTS pin1
//
// Inputs:
// DSR pin2
// CTS pin3
//

#include "Arduino.h"


#define SER Serial1
#define SCON Serial

#define LED 0
#define PERIOD 500

unsigned long lastMillis;


void setup() {
    
    SCON.begin(9600);
    SER.begin(9600);
    
    SCON.write("!#!Hello World!#!\r\n");
    
    pinMode(LED,OUTPUT);

    lastMillis = 0;    
}


void loop() {
    
    if ((millis() - lastMillis) >= PERIOD) {
        digitalWrite(LED, !(digitalRead(LED)));
        lastMillis = millis();
    }

    if (SER.available()) {
            SCON.write(SER.read());
    }

    if (SCON.available()) {
        SER.write(SCON.read());
    }
}

