#include "shell.h"

/**
 * new_process - creating a new process
 * @args: Input commands.
 * Return: (1) on Success, otherwise (0) for failure.
 */
int new_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("not found");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Error in forking process");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
		if (!WIFEXITED(status))
			return (WEXITSTATUS(status));
		else
			return (-1);
	}
	return (-1);
}
