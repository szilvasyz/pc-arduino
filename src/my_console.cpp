#include <stdio.h>      // standard input / output functions
#include <stdlib.h>
#include <string.h>     // string function definitions
#include <unistd.h>     // UNIX standard function definitions
#include <fcntl.h>      // File control definitions
#include <errno.h>      // Error number definitions
#include <termios.h>    // POSIX terminal control definitions
#include <iostream>
#include <sys/ioctl.h>

#include "Arduino.h"
#include "my_console.h"


myConsole Serial("/dev/stdin","/dev/stdout");


using namespace std;


myConsole::myConsole() {
}

myConsole::myConsole(char deviname[], char devoname[])
: myStream(deviname, devoname) {
    
}

void myConsole::begin(int baud) {
    myStream::begin();
}

int myConsole::read() {
    char c = myStream::read();
    if (c <= 0)
            return -1;
    else
            return c == '\n' ? '\r' : c;
}
