#include "shell.h"
/**
 * _strlen - function find length of a string
 *
 * @s: the string
 * Return: as need
*/
int _strlen(const char *s)
{
	int x = 0;

	if (!s)
		return (0);

	while (*s++)
		x++;

	return (x);
}

/**
 * _strcmp - function compare between two strings
 *
 * @s1: first string
 * @s2: second string
 * Return: as need
*/
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((int) (*s1) - (*s2));
}
