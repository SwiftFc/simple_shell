#include "main.h"

/**
 * scan_line - A function to scan a line from standard input
 *
 * Return: pointer to a line
 */

char *scan_line(void)
{
	size_t bufsize = 0;
	char *line = NULL;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		free(line);
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("error while looping the line");
			exit(EXIT_FAILURE);
		}

	}

	return (line);
}
