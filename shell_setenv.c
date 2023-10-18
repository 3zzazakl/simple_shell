#include "shell.h"
/**
 * shell_setenv - setting environment variable
 * @args: argument list.
 * Return: (0) on success, or -1 on failure.
 */
int shell_setenv(char **args)
{
	char *name, *value, *new_env;
	size_t i = 0;
	int j = 0;

	if (args[i] == NULL)
	{
		while (environ[j] != NULL)
		{
			printf("%s\n", environ[j]);
			j++;
		}
		return (0);
	}
	name = _strtok(args[i], "="), value = _strtok(NULL, "=");
	if ((name == NULL) || (value == NULL))
		return (-1);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(name, environ[i], _strlen(name)) == 0)
		{
			if ((args[2] != NULL) && (_strcmp(args[2], "1")) == 0)
				snprintf(environ[i], _strlen(name) + _strlen(value) + 2,
				"%s=%s", name, value);
			return (0);
		}
	}
	new_env = malloc(_strlen(name) + _strlen(value) + 2);
	if (new_env == NULL)
		return (-1);
	sprintf(new_env, "%s=%s", name, value);
	environ = realloc(environ, (i + 2) * sizeof(char *));
	if (environ == NULL)
	{
		free(new_env);
		return (-1);
	}
	environ[i++] = new_env, environ[i] = NULL;
	return (0);
}
