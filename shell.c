#include "shell.h"

/**
 * main - Main function for out simple shell project
 * @argc: no of input arguments.
 * @argv: Input array.
 * Return: (Success) always 0.Z
 */

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		file_mode(argv[1]);
	}
	else if (isatty(STDERR_FILENO) == 1)
	{
		interactive_mode();
	}
	else
	{
		non_interactive_mode();
	}
	return (0);
}
