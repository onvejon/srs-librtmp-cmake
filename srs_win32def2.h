#ifndef SRS_WIN32_DEF_2_H
#define SRS_WIN32_DEF_2_H

/*************************************************************
**************************************************************
* Windows SRS-LIBRTMP solution
**************************************************************
*************************************************************/
// for srs-librtmp, @see https://github.com/ossrs/srs/issues/213
#ifdef _WIN32
    #include "srs_win32def.h"
    // for time.
    #define _CRT_SECURE_NO_WARNINGS
    #include <time.h>
   
    #define PRId64 "lld"
    
    // for inet helpers.
    typedef int socklen_t;
    //const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);
    
    // for mkdir().
    #include<direct.h>
    
    // for open().
    typedef int mode_t;
    #define S_IRUSR 0
    #define S_IWUSR 0
    #define S_IXUSR 0
    #define S_IRGRP 0
    #define S_IWGRP 0
    #define S_IXGRP 0
    #define S_IROTH 0
    #define S_IXOTH 0
    
    // for file seek.
    #include <io.h>
    #include <fcntl.h>
    
#ifdef __cplusplus
	extern "C" {
#endif   
		int gettimeofday(struct timeval* tv, struct timezone* tz);
		// for pid.
		typedef int pid_t;
		pid_t getpid(void);

		// for socket.
		ssize_t writev(int fd, const struct iovec *iov, int iovcnt);
		typedef int64_t useconds_t;
		int usleep(useconds_t usec);
		int socket_setup();
		int socket_cleanup();
#ifdef __cplusplus
	}
#endif       
    // others.

	//#define snprintf _snprintf
    
#endif

#endif