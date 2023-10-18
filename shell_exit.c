#include "shell.h"
/**
 * shell_exit - function to handle exit command
 *
 * @args: input argument
 * Return: as need
*/

int shell_exit(char **args)
{
	int i, status;
	char *nl;
	const char *err_msg;

	if (args[1] != NULL)
	{
		if (_strcmp(args[1], "HBTN") == 0)
		{
			err_msg = "Invalid argument";
			write(STDERR_FILENO, err_msg, _strlen(err_msg));
			nl = "\n";
			write(STDERR_FILENO, nl, 1);
			return (EXIT_FAILURE);
		}
		for (i = 0; args[1][i] != '\0'; i++)
		{
			if (!_isdigit(args[1][i]))
			{
				err_msg = "Invalid arguments\n";
				write(STDERR_FILENO, args[1], _strlen(args[1]));
				nl = "\n";
				write(STDERR_FILENO, nl, 1);
				return (EXIT_FAILURE);
			}
		}
		status = _atoi(args[1]);
		return (status);
	}
	else
		return (0);
}
