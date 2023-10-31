#include "main.h"

/**
 * create_process - A function to create a new process
 * @args: array string flags
 *
 * Return: 1 on success, else 0
 */

int create_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("error in forking new process Id");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			perror("error in new procees");
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (-1);
}
