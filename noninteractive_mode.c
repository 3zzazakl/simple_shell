#include "shell.h"
/**
 * non_interactive_mode - function to execute in non interactive mode
*/
void non_interactive_mode(void)
{
	char *input, **args;
	int st;

	while (1)
	{
		write(0, "$ ", 2);
		input = read_stream();
		args = token_line(input);
		st = execute_command(args);

		free(input);
		free(args);

		if (st >= 0)
		{
			exit(st);
		}
		else
		{
			continue;
		}
	}
}
