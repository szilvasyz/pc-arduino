# pc-arduino
Trying/developing Arduino sketches on PC

This small project has been started for trying a serial communication sketch (such as a GSM or GPS module) on PC using GCC with your favourite IDE/debugger. The hardware is very simple: it is only a USB/serial converter with TTL inputs/outputs.
In the prototype a CP2102 converter was used which has all serial signals presented on soldering pads.

The serial port device is defined in "Arduino.h" as SERIAL_PORT.

## In Arduino sketch you can use:
- "Serial" as local console
- "Serial1" as TTL serial converter TX/RX

### Digital outputs:
- pin0: DTR signal on serial converter
- pin1: RTS signal on serial converter

### Digital Inputs:
- pin2: DSR signal on serial converter
- pin3: CTS signal on serial converter


## Following Arduino keywords and functions have been implemented:

### Keywords:
- INPUT
- INPUT_PULLUP
- OUTPUT
- LOW
- HIGH

### Functions:
- void pinMode(int,t_pinMode);
- void digitalWrite(int,int);
- int  digitalRead(int);
- void setup();
- void loop();
- void delay(unsigned long);
- unsigned long millis();

### Serial and Serial1 methods:
- void begin(int baud);
- void end();
- uint8_t write(uint8_t val);
- uint8_t write(char * str);
- uint8_t write(char * buf, int len);
- int available();
- int read();
