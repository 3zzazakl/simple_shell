#ifndef __SIMPLE_SHELL__
#define __SIMPLE_SHELL__
/**********HEADERS_DECLARATIONS******************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <stddef.h>
#include <ctype.h>
#include <limits.h>
/**********MACROS***********/
extern char **environ;
#define delimeter " \t\r\n\a\""
#define BUF_MAX 2097152
#define BUFFER_SIZE 128
/************FUNCTION_DECLARATIONS******************/
void interactive_mode(void);
void non_interactive_mode(void);
int execute_command(char **args);
ssize_t _getline(char **line, size_t *buffer_size, int fd);
int new_process(char **args);
char *read_line(void);
char *read_stream(void);
void file_mode(char *filename);
int shell_echo(char **args);
int shell_exit(char **args);
int shell_help(char **args);
char **token_line(char *line);
/*************String_Functions*********************/
int _atoi(const char *str);
int _getchar(void);
int _isdigit(int c);
int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s);
char *_strchr(const char *s, int c);
char *_strtok(char *line, const char *delim);
/***************ENV_FUNCTIONS**************/
int shell_env(char **args);
int shell_cd(char **args);
char *shell_getenv(const char *name);
int shell_unsetenv(char **args);
int shell_setenv(char **args);
#endif /*__SIMPLE_SHELL__*/
