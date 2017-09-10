/*
 * my_console.h
 *
 *  Created on: Aug 31, 2017
 *      Author: szilva
 */

#ifndef MY_CONSOLE_H_
#define MY_CONSOLE_H_

#include <termios.h>    // POSIX terminal control definitions
#include <inttypes.h>

#include "my_stream.h"


class myConsole: public myStream {

public:
    myConsole();
    myConsole(char * deviname, char * devoname);
    void begin(int baud);
    int read();

};



#endif /* MY_CONSOLE_H_ */
