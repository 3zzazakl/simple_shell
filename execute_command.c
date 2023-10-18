#include "shell.h"

/**
 * execute_command - checking if command builtin or executable
 * @args: The input command
 * Return: (1) on Success or (-1) for failure.
 */
int execute_command(char **args)
{
	size_t i = 0;
	char *builtin_commands[] = {"cd", "env", "exit", "help",
					"setenv", "unsetenv", "echo"};
	int (*builtin_functions[])(char **) = {&shell_cd, &shell_env,
		&shell_exit, &shell_help, &shell_setenv, &shell_unsetenv, &shell_echo};

	if (args[0] == NULL || args[0][0] == '\0')
		return (-1);

	if (_strcmp(args[0], "echo") == 0)
		return (shell_echo(args));

	for (i = 0; i < sizeof(builtin_commands) / sizeof(builtin_commands[0]); i++)
	{
		if (_strcmp(args[0], builtin_commands[i]) == 0)
			return ((*builtin_functions[i])(args));
	}

	return (new_process(args));
}
