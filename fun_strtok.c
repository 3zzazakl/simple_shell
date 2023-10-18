#include "shell.h"
/**
 * _strtok - function to impliment strtok function
 *
 * @line: input to split
 * @delim: the place split at it
 * Return: as need
*/
char *_strtok(char *line, const char *delim)
{
	char *s = NULL;
	char *t;

	if (line == NULL && s == NULL)
		return (NULL);

	if (line != NULL)
		s = line;

	while (*s != '\0' && strchr(delim, *s) != NULL)
		s++;

	if (*s == '\0')
	{
		s = NULL;
		return (NULL);
	}
	t = s;
	while (*s != '\0' && strchr(delim, *s) == NULL)
		s++;

	if (*s != '\0')
	{
		*s = '\0';
		s++;
	}
	return (t);
}
