#include "shell.h"
/**
 * shell_help - function to handle builtin commands
 *
 * @args: input command
 * Return: as need
*/
int shell_help(char **args)
{
	char *builtin_commands[] = {"cd", "env", "exit", "help"};
	const char *helpmes = "\n--help simple shell--\n"
						  "Type a command and its arguments, then enter\n"
						  "Built-in command\n";
	const char *infomes = "Use the command for getting info\n\n";
	const char *com = " -> ", *n = "\n";
	unsigned long int i = 0;
	(void)(**args);

	write(STDOUT_FILENO, helpmes, _strlen(helpmes));

	for (; i < sizeof(builtin_commands) / sizeof(char *); i++)
	{
		write(STDOUT_FILENO, com, _strlen(com));
		write(STDOUT_FILENO, builtin_commands[i], _strlen(builtin_commands[i]));
		write(STDOUT_FILENO, n, _strlen(n));
	}
	write(STDOUT_FILENO, infomes, _strlen(infomes));
	return (-1);
}
