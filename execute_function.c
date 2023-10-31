#include "main.h"


/**
 * exec_arg - A function to excute a programs
 * @args: arugumrnts it takes
 *
 * Return: 0 on fail otherwsie 1 on sucess
 */

int exec_arg(char **args)
{
	char *my_built_list[] = {
		"env",
		"exit",
	};

	int (*my_built_func[])(char **) = {
		/*&my_cd,*/
		&my_env,
		&my_exit,
	};
	size_t x = 0;

	if (args[0] == NULL)
		return (-1);
	for (; x < sizeof(my_built_list) / sizeof(char *); x++)
	{
		if (mycustom_strcmp(args[0], my_built_list[x]) == 0)
		{
			return ((*my_built_func[x])(args));
		}
	}
	if (mycustom_strcmp(args[0], "exit") == 0)
	{
		return (my_exit(args));
	}
	else if (mycustom_strcmp(args[0], "env") == 0)
	{
		return (my_env(args));
	}

	return (create_process(args));
}