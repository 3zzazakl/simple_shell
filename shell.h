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
int execute_command(char **args);
ssize_t _getline(char **line, size_t *buffer_size, int fd);
int new_process(char **args);


/*************String_Functions*********************/
int _atoi(const char *str);

#endif /*__SIMPLE_SHELL__*/
