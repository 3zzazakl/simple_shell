#include "shell.h"
/**
 * _atoi - function to convert str to int
 *
 * @str: str to be converted
 * Return: as need
 *
*/
int _atoi(const char *str)
{
	int res = 0, x = 1;

	if (*str == '-')
	{
		x = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * x);
}
