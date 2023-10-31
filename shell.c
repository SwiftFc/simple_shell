#include "main.h"

/**
 * main - A function to check if our shell is interactive
 *
 * Return: 0 on success
 */

int main(void)
{
	if (isatty(STDIN_FILENO) == 1) /* isatty func to see if shell is interactive*/
		myshell_works(); /* lets check if our shell is interactive*/
	else
		myshell_isnot(); /* lets see if the shell is not interactive*/

	return (0);
}



/**
 * myshell_works - A function to print a prompt for the shell to work
 *
 * Return: void
 */

void myshell_works(void)
{
	char *line;
	char **args;
	int status = -1;

	do {
		write(STDOUT_FILENO, "henry$$ ", 8);
		line = scan_line();
		args = divide_line(line);
		status = exec_arg(args);
		free(line);
		free(args);

	} while (status != -2);
}



/**
 * myshell_isnot - A function for non interactive shell
 *
 * Return: void
 */

void myshell_isnot(void)
{
	char *line;
	char **args;
	int status;

	do {
		line = get_stream();
		args = divide_line(line);
		status = exec_arg(args);
		free(line);
		free(args);

		if (status >= 0 || status == -2)
			break;

	} while (status == -1);
}
