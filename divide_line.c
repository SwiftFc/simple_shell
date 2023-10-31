#include "main.h"
/**
 * divide_line - A function to divide a string
 * @line: string to be utilised
 *
 * Return: pointer to a new element
 */
char **divide_line(char *line)
{
	int bufsize = 64;
	int x = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;
	char *TOK_DELIM = " \t\r\n\a";

	if (!tokens)
	{
		perror("error in allocation memory");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		if (token[0] == '#')
			break;
		tokens[x] = token;
		x++;

		if (x >= bufsize)
		{
			bufsize += bufsize;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("error in reallocation memeory");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[x] = NULL;
	return (tokens);
}
