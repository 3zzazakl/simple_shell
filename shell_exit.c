#include "shell.h"
/**
 * shell_exit - function to handle exit command
 *
 * @args: input argument
 * Return: as need
*/
int shell_exit(char **args)
{
	int x, st = 0;
	char *n;

	if (args[1] != NULL)
	{
		for (x = 0; args[1][x] != '\0'; x++)
		{
			if (!_isdigit(args[1][x]))
			{
				const char *errmeg = "Invalid argument: ";

				write(STDERR_FILENO, errmeg, _strlen(errmeg));
				write(STDERR_FILENO, args[1], _strlen(args[1]));
				n = "\n";
				write(STDERR_FILENO, n, 1);
				return (EXIT_FAILURE);
			}
		}
		st = _atoi(args[1]);
		return (st);
	}
	else
		return (0);
}
