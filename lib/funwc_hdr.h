#ifndef FUNWC_HDR
#define FUNWC_HDR /* Prevent accidental double inclusion */

#include <sys/types.h>      /* Type definitions used by many programs */
#include <stdio.h>          /* Standard I/O functions */
#include <stdlib.h>         /* Prototypes of commonly used library functions, 
                               plus EXIT_SUCCESS and EXIT_FAILURE constants */ 
#include <unistd.h>         /* Prototypes for many system calls */
#include <errno.h>          /* Declares errno and defines error constants */ 
#include <string.h>         /* Commonly used string-handling functions */

typedef enum { FALSE, TRUE } Boolean;

#define min(m,n) ((m) < (n) ? (m) : (n)) 
#define max(m,n) ((m) > (n) ? (m) : (n))

#endif /* FUNWC_HDR */
