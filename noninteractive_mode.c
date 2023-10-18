#include "shell.h"
/**
 * non_interactive_mode - function to execute in non interactive mode
*/
void non_interactive_mode(void)
{
	char *input, **arg;
	int st;

	while (1)
	{
		write(0, "$ ", 2);
		input = read_stream();
		arg = token_line(input);
		st = execute_command(arg);

		free(input);
		free(arg);

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
