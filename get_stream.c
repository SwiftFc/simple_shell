#include "main.h"

/**
 * get_stream - A function to get a line from the stream
 *
 * Return: pointer to line
 */

char *get_stream(void)
{
	size_t bufsize = 0;
	char *line = NULL;
	ssize_t cha_read;

	cha_read = getline(&line, &bufsize, stdin);

	if (cha_read == -1)
	{
		free(line);

		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Error getting input");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
