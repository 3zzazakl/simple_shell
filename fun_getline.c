#include "shell.h"
/**
 *_getline - function to read a line
 *@line: line to read
 *@buffer_size: max. total size of buffer
 *@fd: include the result of the function
 *Return: as need
 *
*/
ssize_t _getline(char **line, size_t *buffer_size, int fd)
{
	size_t rch = 0;
	int cuch;
	*line = (char *)malloc(BUFFER_SIZE);

	if (*line == NULL)
	{
		perror("malloc");
		return (-1);
	}
	while (1)
	{
		cuch = read(fd, *line + rch, 1);
		if (cuch < 0)
		{
			perror("read");
			return (-1);
		}
		else if (cuch == 0 || (*line)[rch] == '\n')
		{
			if (rch == 0 && cuch == 0)
			{
				free(*line);
				return (-1);
			}
			(*line)[rch] = '\0';
			return (rch);
		}
		else
		{
			rch++;
			if (rch >= *buffer_size)
			{
				*buffer_size += buffer_size;
				*line = (char *)realloc(*line, *buffer_size);

			}
		}
	}
}
