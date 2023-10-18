#include "shell.h"

/**
 * read_stream - Reading input data in non-interactive mode.
 * Return: pointer to str with its line content.
 */
char *read_stream(void)
{
	int buffer = 1024, i = 0, character;
	char *line = malloc(buffer), *new_line;

	if (!line)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = _getchar();
		if (character == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (character == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		else
			line[i] = character;
		i++;
		if (i >= buffer)
		{
			buffer += buffer;
			new_line = realloc(line, buffer);
			if (!line)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
			line = new_line;
		}
	}
}
