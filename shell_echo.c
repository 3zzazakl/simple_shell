#include "shell.h"
/**
 * shell_echo - function for echo command
 *
 * @args: input command
 * Return: as need
*/
int shell_echo(char **args)
{
	int x = 1;
	const char *n;

	while (args[x] != NULL)
	{
		write(STDOUT_FILENO, args[x], _strlen(args[x]));
		write(STDOUT_FILENO, " ", 1);
		x++;
	}
	n = "\n";
	write(STDOUT_FILENO, n, 1);
	return (0);
}
