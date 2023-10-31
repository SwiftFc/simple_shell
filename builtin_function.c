#include "main.h"

/**
 * my_exit - A function to exit shell
 *
 * @args: command to be run
 * Return: 0 on success
 */

int my_exit(char **args)
{
	if (args[1] != NULL)
	{
		char *endptr;
		long status = strtol(args[1], &endptr, 10);

		if (*endptr != '\0')
		{
			fprintf(stderr, "Usage: close and exit status\n");
				return (1);
		}
		exit((int)status);
	}
	exit(0);
}

/**
 * my_env - get environ function to be implemented
 * @args: arguments
 *
 * Return: 1 means successful
 */

int my_env(char **args)
{
	char **env_var;

	while (*env_var)
	{
		char *env_str = *env_var;
		size_t len = mycustom_strlen(env_str);

		if (len > 0)
		{
			write(STDOUT_FILENO, env_str, len);
			write(STDOUT_FILENO, "\n", 1);
		}

		env_var++;
	}

	(void)args;

	return (0);
}
