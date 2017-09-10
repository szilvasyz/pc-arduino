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

//void myConsole::begin(int baud) {
//	begin();
//}
//
//void myConsole::begin() {
//    const char indev[]  = "/dev/stdin";
//    const char outdev[] = "/dev/stdout";
//
//    /* Open File Descriptor */
//	fd_in  = ::open( indev , O_RDWR| O_NONBLOCK | O_NDELAY );
//	fd_out = ::open( outdev, O_RDWR| O_NONBLOCK | O_NDELAY );
//
//	/* Error Handling */
//	if ( fd_in < 0 ) {
//		cout << "Error " << errno << " opening /dev/stdin: " << strerror (errno) << endl;
//	}
//
//	if ( fd_out < 0 ) {
//		cout << "Error " << errno << " opening /dev/stdout: " << strerror (errno) << endl;
//	}
//
//	/* *** Configure Port *** */
//}
//
//
//void myConsole::end() {
//
//	/* Close File Descriptor */
//	::close(fd_in);
//	::close(fd_out);
//}
//
//
//uint8_t myConsole::write(uint8_t val) {
//	return ::write( fd_out, &val, 1 );
//}
//
//
//uint8_t myConsole::write(char str[]) {
//	int n = 0;
//	while (str[n] != '\0') n++;
//	return ::write( fd_out, str, n );
//}
//
//
//uint8_t myConsole::write(char * buf, int len) {
//	return ::write( fd_out, buf, len );
//}
//
//
//int myConsole::read() {
//	char c;
//	if (::read( fd_in, &c , 1 ) <= 0)
//		return -1;
//	else
//		return c == '\n' ? '\r' : c;
//}
//
//
//int myConsole::available() {
//    int bytes;
//
//    ioctl(fd_in, FIONREAD, &bytes);
//    return bytes;    
//
///*	int s;
//    struct timeval tv;
//    fd_set rfds;
//
//    FD_ZERO(&rfds);
//    FD_SET(fd_in, &rfds);
//
//    tv.tv_sec = 0;
//    tv.tv_usec = 0;
//
//	s = ::select(1,&rfds,NULL,NULL,&tv);
//	if (s<0) return 0;
//	else return s;*/
//}
//
//
