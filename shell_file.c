#include "shell.h"

/**
 * file_mode - function to access files in our shell.
 * @filename: name of the file.
 */
void file_mode(char *filename)
{
	int fd, status;
	char *line = NULL, **args;
	size_t buffer = 0;

	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		perror("ERROR OPENING");
		exit(EXIT_FAILURE);
	}

	while (_getline(&line, &buffer, fd) != -1)
	{
		args = token_line(line);
		status = execute_command(args);
		free(args);
		if (status >= 0)
			exit(status);
		free(line), close(fd);
	}
}
