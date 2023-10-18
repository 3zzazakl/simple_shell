#include "shell.h"
/**
 * tokens_line - function split command into tokens
 * @line: input to split
 * Return: as need
*/
char **token_line(char *line)
{
    int buff = 1024, m = 0;
    char **tokens = malloc(buff * sizeof(char *)), *token;

    if (!tokens)
    {
        const char *errmeg = "Error in allocate memory";

        write(STDERR_FILENO, errmeg, _strlen(errmeg));
        exit(EXIT_FAILURE);
    }
    token = my_strtok(line, delimeter);
    while (token != NULL)
    {
        if (token[0] == '#')
            break;
        tokens[m] = token;
        m++;
        if (m >= buff)
        {
            buff += buff;
            tokens = realloc(tokens, buff * sizeof(char *));
            if (!tokens)
            {
                const char *errmeg = "Error in split line into tokens";

                write(STDERR_FILENO, errmeg, _strlen(errmeg));
                exit(EXIT_FAILURE);
            }
        }
        token = my_strtok(NULL, delimeter);
    }
    tokens[m] = NULL;
    return (tokens);
}