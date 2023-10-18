#include "shell.h"
/**
 * _strchr - function detect the first appear of a character
 *
 * @s: string contain charcater
 * @c: the character
 * Return: as need
*/
char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}
