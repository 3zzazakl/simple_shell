#include "shell.h"
/**
 * _isdigit - function detect if character digit or not
 *
 * @c: character to detect
 * Return: as need
*/
int _isdigit(int c)
{
	return ((c >= '0' && c <= '9') ? 1 : 0);
}
