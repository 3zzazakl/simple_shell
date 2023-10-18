#ifndef __SIMPLE_SHELL__
#define __SIMPLE_SHELL__

/**********HEADERS_DECLARATIONS******************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>



/************FUNCTION_DECLARATIONS******************/
void interactive_mode(void);
void non_interactive_mode(void);

#endif /*__SIMPLE_SHELL__*/
