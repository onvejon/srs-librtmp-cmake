
#ifndef SRS_WIN32_DEF_H
#define SRS_WIN32_DEF_H
/*************************************************************
**************************************************************
* Windows SRS-LIBRTMP pre-declare
**************************************************************
*************************************************************/
// for srs-librtmp, @see https://github.com/ossrs/srs/issues/213
#ifdef _WIN32
    // include windows first.
	
	#include <inttypes.h>
	#include <WS2tcpip.h>
	#include <ws2def.h>
	#include <Windows.h>
	#include <stdint.h>
    // the type used by this header for windows.
    typedef unsigned long long u_int64_t;
    //typedef long long int64_t;
    typedef unsigned int u_int32_t;
    //typedef u_int32_t uint32_t;
    //typedef int int32_t;
    typedef unsigned char u_int8_t;
	//typedef char int8_t;
    typedef unsigned short u_int16_t;
    //typedef short int16_t;
    typedef int64_t ssize_t;

    struct iovec {
        void  *iov_base;    /* Starting address */
        size_t iov_len;     /* Number of bytes to transfer */
    };
#endif

#include <sys/types.h>

#endif