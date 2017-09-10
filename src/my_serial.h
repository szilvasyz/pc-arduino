/*
 * my_serial.h
 *
 *  Created on: Aug 31, 2017
 *      Author: szilva
 */

#ifndef MY_SERIAL_H_
#define MY_SERIAL_H_

#include <termios.h>    // POSIX terminal control definitions
#include <inttypes.h>

#include "my_stream.h"

class mySerial: public myStream {

public:
    mySerial();
	mySerial(char * devname);
	void begin(int baud);

//	void begin(int baud);
//	void end();
//	uint8_t write(uint8_t val);
//	uint8_t write(char * str);
//	uint8_t write(char * buf, int len);
//	int available();
//	int read();
    void setDTR(int state);
    void setRTS(int state);
    int getDTR();
    int getRTS();
    int getDSR();
    int getCTS();
//
//private:
//	int fd;
//	char dev[80];
//	struct termios tty;
//
};



#endif /* MY_SERIAL_H_ */
