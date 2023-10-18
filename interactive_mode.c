#include "shell.h"

/**
 * interactive_mode - checking our shell mode.
 */
void interactive_mode(void)
{
	char *line, **args;
	int status = -1;

	do {
		write(0, "$ ", 2);
		line = read_line();
		args = token_line();
		status = execute_command(args);

		free(line), free(args);

		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}
