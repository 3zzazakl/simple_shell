#include "shell.h"

/**
 * shell_getenv - get env variables.
 * @name: name of variable.
 * Return: value of variable.
 */
char *shell_getenv(const char *name)
{
	size_t i = 0;

	while (environ[i] != NULL)
	{
		if (strstr(environ[i], name) == environ[i])
			return (environ[i] + _strlen(name));
		i++;
	}
	return (NULL);
}
/**
 * shell_unsetenv - unset the environment variable.
 * @args: argument list.
 * Return: (0) on Success, or (-1) on failure.
 */
int shell_unsetenv(char **args)
{
	size_t i = 0;
	char *name = args[1];

	if (name == NULL)
		return (-1);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(name, environ[i], _strlen(name)) == 0)
		{
			while (environ[i] != NULL)
			{
				environ[i] = environ[i + 1];
				i++;
			}
			return (0);
		}
	}
	perror("unsetenv error");
	return (-1);
}
