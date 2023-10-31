#include "main.h"

/**
 * mycustom_strlen - A C function to know the length of a string
 * @z: pointer to be used
 *
 * Return: 0 on sucess
 */

int mycustom_strlen(const char *z)
{
	const char *p = z;

	while (*p != '\0')
	{
		p++;
	}
	return (p - z);
}

/**
 * mycustom_strcmp - A function to compare two strings
 * @fs: First string to be used
 * @ss: Secong string to be used
 *
 * Return: change of both
 */

int mycustom_strcmp(char *fs, char *ss)
{
	while (*fs != '\0' && (*fs == *ss))
	{
		fs++;
		ss++;
	}
	return (*fs - *ss);
}