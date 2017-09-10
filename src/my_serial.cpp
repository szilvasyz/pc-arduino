#include <stdio.h>      // standard input / output functions
#include <stdlib.h>
#include <string.h>     // string function definitions
#include <unistd.h>     // UNIX standard function definitions
#include <fcntl.h>      // File control definitions
#include <errno.h>      // Error number definitions
#include <termios.h>    // POSIX terminal control definitions
#include <iostream>
#include <sys/ioctl.h>
#include <sys/file.h>
 
#include "Arduino.h"
#include "my_serial.h"


using namespace std;


mySerial Serial1(SERIAL_PORT);


mySerial::mySerial() {
}

mySerial::mySerial(char * devname) 
: myStream(devname, devname) {
}

void mySerial::begin(int baud) {

	/* Open File Descriptor */
	fd_in  = ::open( devi, O_RDWR | O_NONBLOCK | O_NDELAY | O_EXCL );
	fd_out = fd_in;

	/* Error Handling */
	if ( fd_in < 0 ) {
		cout << "Error " << errno << " opening " << devi << ": " << strerror (errno) << endl;
                return;
	}
        
        
	/* *** Configure Port *** */
        if ( ::ioctl( fd_in, TIOCEXCL ) != 0 ) {
		cout << "Error " << errno << " opening " << devi << ": " << strerror (errno) << endl;
                return;
	}

	memset (&tty, 0, sizeof tty);

	/* Error Handling */
	if ( tcgetattr ( fd_in, &tty ) != 0 )	{
		cout << "Error " << errno << " from tcgetattr: " << strerror(errno) << endl;
	}

	/* Set Baud Rate */
	cfsetospeed (&tty, baud);
	cfsetispeed (&tty, baud);

	/* Setting other Port Stuff */
	tty.c_cflag     &=  ~PARENB;        // Make 8n1
	tty.c_cflag     &=  ~CSTOPB;
	tty.c_cflag     &=  ~CSIZE;
	tty.c_cflag     |=  CS8;
	tty.c_cflag     &=  ~CRTSCTS;       // no flow control
	tty.c_lflag     =   0;          // no signaling chars, no echo, no canonical processing
	tty.c_oflag     =   0;                  // no remapping, no delays
	tty.c_cc[VMIN]      =   0;                  // read doesn't block
	tty.c_cc[VTIME]     =   5;                  // 0.5 seconds read timeout

	tty.c_cflag     |=  CREAD | CLOCAL;     // turn on READ & ignore ctrl lines
	tty.c_iflag     &=  ~(IXON | IXOFF | IXANY);// turn off s/w flow ctrl
	tty.c_lflag     &=  ~(ICANON | ECHO | ECHOE | ISIG); // make raw
	tty.c_oflag     &=  ~OPOST;              // make raw

	/* Flush Port, then applies attributes */
	tcflush( fd_in, TCIFLUSH );

	if ( tcsetattr ( fd_in, TCSANOW, &tty ) != 0) {
		cout << "Error " << errno << " from tcsetattr" << endl;
	}

}


void mySerial::setDTR(int state) {
    int status;

    ioctl(fd_in, TIOCMGET, &status);

    status = (status & ~TIOCM_DTR) | (state != LOW ? 0 : TIOCM_DTR);

    ioctl(fd_in, TIOCMSET, &status);
}


void mySerial::setRTS(int state) {
    int status;

    ioctl(fd_in, TIOCMGET, &status);

    status = (status & ~TIOCM_RTS) | (state != LOW ? 0 : TIOCM_RTS);

    ioctl(fd_in, TIOCMSET, &status);
}


int mySerial::getDTR() {
    int status;

    ioctl(fd_in, TIOCMGET, &status);

    return status & TIOCM_DTR ? LOW : HIGH ;
}


int mySerial::getRTS() {
    int status;

    ioctl(fd_in, TIOCMGET, &status);

    return status & TIOCM_RTS ? LOW : HIGH ;
}


int mySerial::getDSR() {
    int status;

    ioctl(fd_in, TIOCMGET, &status);

    return status & TIOCM_DSR ? LOW : HIGH ;
}


int mySerial::getCTS() {
    int status;

    ioctl(fd_in, TIOCMGET, &status);

    return status & TIOCM_CTS ? LOW : HIGH ;
}
