#include "shell.h"

/**
 * shell_cd - CD function
 * @args: input arguments
 * Return: (0) on success, otherwise (-1) on failure.
 */
int shell_cd(char **args)
{
	char *new_dir = args[1], cwd[1024], *pwd_args[4], *oldpwd, *oldargs[4];

	if (new_dir == NULL)
	{
		new_dir = shell_getenv("HOME");
		if (new_dir == NULL)
		{
			fprintf(stderr, "shell_cd: not Home\n");
			return (-1);
		}
	}
	if (chdir(new_dir) != 0)
	{
		perror("Shell_cd");
		return (-1);
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("shell_cd");
		return (-1);
	}
	pwd_args[0] = "setenv", pwd_args[1] = "PWD",
			pwd_args[2] = cwd, pwd_args[3] = NULL;
	if (shell_setenv(pwd_args) != 0)
	{
		fprintf(stderr, "shell_cd failed to pwd\n");
		return (-1);
	}
	oldpwd = shell_getenv("PWD");

	if (oldpwd != NULL)
	{
		oldargs[0] = "setenv", oldargs[1] = "OLDPWD",
				oldargs[2] = oldpwd, oldargs[3] = NULL;
	}
	if (shell_setenv(oldargs) != 0)
	{
		fprintf(stderr, "shell_cd: failed to set oldpwd\n");
		return (-1);
	}
	return (0);
}
