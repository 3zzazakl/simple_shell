#include "shell.h"

/**
 * read_line - getting line from user.
 * Return: (pointer to str and its line)
 */
char *read_line(void)
{
	char *line = NULL;
	size_t buffer = 0;
	int eof_detect = 0, fd = 0;
	const char *eof_msg;

	if (_getline(&line, &buffer, fd) == -1)
	{
		if (line == NULL)
			eof_detect = 1;
		else
			free(line);

		if (eof_detect)
		{
			eof_msg = "End of file.\n";
			write(STDERR_FILENO, eof_msg, _strlen(eof_msg));
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Error in reading");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
