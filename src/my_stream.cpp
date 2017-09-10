#include <stdio.h>      // standard input / output functions
#include <stdlib.h>
#include <string.h>     // string function definitions
#include <unistd.h>     // UNIX standard function definitions
#include <fcntl.h>      // File control definitions
#include <errno.h>      // Error number definitions
#include <termios.h>    // POSIX terminal control definitions
#include <iostream>
#include <sys/ioctl.h>

#include "my_stream.h"


using namespace std;


myStream::myStream() {
}

myStream::~myStream() {
}


myStream::myStream(char * deviname, char * devoname) {
	char * c;

	c = devi; while ((*c++ = *deviname++) != '\0');
    c = devo; while ((*c++ = *devoname++) != '\0');

    fd_in = -1;
    fd_out = -1;
}

void myStream::begin() {

	/* Open File Descriptor */
	fd_in  = ::open( devi, O_RDONLY| O_NONBLOCK | O_NDELAY );
	fd_out = ::open( devo, O_WRONLY| O_NONBLOCK | O_NDELAY );

	/* Error Handling */
	if ( fd_in < 0 ) {
		cout << "Error " << errno << " opening " << devi << ": " << strerror (errno) << endl;
	}

	if ( fd_out < 0 ) {
		cout << "Error " << errno << " opening " << devo << ": " << strerror (errno) << endl;
	}

}


void myStream::end() {

	/* Close File Descriptor */
	close(fd_in);
	close(fd_out);
}


uint8_t myStream::write(uint8_t val) {
	return ::write( fd_out, &val, 1 );
}


uint8_t myStream::write(char str[]) {
	int n = 0;
	while (str[n] != '\0') n++;
	return ::write( fd_out, str, n );
}


uint8_t myStream::write(char * buf, int len) {
	return ::write( fd_out, buf, len );
}


int myStream::read() {
	char c;
	if (::read( fd_in, &c , 1 ) <= 0)
		return -1;
	else
		return c;
}

int myStream::available() {
    int bytes;

    ioctl(fd_in, FIONREAD, &bytes);
    return bytes;    
}


