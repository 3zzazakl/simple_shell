#include "shell.h"

/**
 * shell_env - print env variables.
 * @args: input/
 * Return: (0) on Success, or (1) on failure.
 */
int shell_env(char **args)
{
	int i = 0;

	args = environ;

	while (args[i] != NULL)
	{
		write(STDOUT_FILENO, args[i], _strlen(args[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
