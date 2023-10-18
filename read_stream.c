#include "shell.h"

/**
 * read_stream - Reading input data in non-interactive mode.
 * Return: pointer to str with its line content.
 */
char *read_stream(void)
{
	int buffer = 1024, i, character;
	char *line = malloc(sizeof(sizeof(char) * buffer));
	const char *alloc_err_msg;

	if (line ==  NULL)
	{
		alloc_err_msg = "allocate error in read stream\n";
		write(STDERR_FILENO, alloc_err_msg, _strlen(alloc_err_msg));
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = _getline();
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
			line = realloc(line, buffer);
			if (line == NULL)
			{
				alloc_err_msg = "Error in allocating memory\n";
				write(STDERR_FILENO, alloc_err_msg, _strlen(alloc_err_msg));
				exit(EXIT_FAILURE);
			}
		}
	}
}
