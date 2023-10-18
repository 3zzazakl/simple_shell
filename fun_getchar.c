#include "shell.h"
/**
 * _getchar - function to detect the end of file
 *
 * Return: as need
*/
int _getchar(void)
{
	char i;
	ssize_t z = read(STDIN_FILENO, &i, 1);

	if (z == 1)
	{
		return (i);
	}
	else if (z == 0)
	{
		return (EOF);
	}
	else
	{
		return (-1);
	}
}
