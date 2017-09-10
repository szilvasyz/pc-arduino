#ifndef ARDUINO_H
#define ARDUINO_H

#include <stdio.h>      // standard input / output functions
#include <stdlib.h>
#include <string.h>     // string function definitions
#include <unistd.h>     // UNIX standard function definitions
#include <fcntl.h>      // File control definitions
#include <errno.h>      // Error number definitions
#include <termios.h>    // POSIX terminal control definitions
#include <iostream>
#include <sys/ioctl.h>

#include "my_serial.h"
#include "my_console.h"

extern myConsole Serial;
extern mySerial Serial1;

#define SERIAL_PORT "/dev/ttyUSB0"
#define LOW  0
#define HIGH 1


enum t_pinMode {
    INPUT,
    INPUT_PULLUP,
    OUTPUT
};

void pinMode(int,t_pinMode);
void digitalWrite(int,int);
int  digitalRead(int);
void setup();
void loop();
void delay(unsigned long);
unsigned long millis();
void millis_init();


#endif // ARDUINO_H
