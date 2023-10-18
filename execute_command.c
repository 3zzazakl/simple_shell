#include "shell.h"

/**
 * execute_command - checking if command builtin or executable
 * @args: The input command
 * Return: (1) on Success or (-1) for failure.
 */
int execute_command(char **args)
{
	size_t i = 0;
	char *built_commands[] = {"cd", "env", "exit", "help",
					"setenv", "unsetenv", "echo"};
	int (*builtin_functions[])(char **) = {&shell_cd, &shell_env,
		&shell_exit, &shell_help, &shell_setenv, &shell_unsetenv, &shell_echo};

	if (args[0] == NULL || args[0][0] == '\0')
		return (-1);

	for (i = 0; i < sizeof(built_commands) / sizeof(built_commands[0]); i++)
	{
		if (_strcmp(args[0], built_commands[i]) == 0)
			return ((*builtin_functions[i])(args));
	}

	return (new_process(args));
}
