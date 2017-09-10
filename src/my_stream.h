#ifndef MYSTREAM_H
#define MYSTREAM_H

#include <termios.h>    // POSIX terminal control definitions
#include <inttypes.h>

class myStream
{

public:
    myStream();
    myStream(char * deviname, char * devoname);
    ~myStream();

    void begin();
    void end();
    uint8_t write(uint8_t val);
    uint8_t write(char * str);
    uint8_t write(char * buf, int len);
    int available();
    int read();

public:
    int fd_in;
    int fd_out;
    char devi[80];
    char devo[80];
    struct termios tty;

};

#endif // MYSTREAM_H
