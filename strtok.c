#include "shell.h"

/**
 * _strtok - tokenizes the strtok.
 * @buffer: the string of str.
 * @delim: the dividing char of str.
 * Return: p on success or NULL if fails.
 */
char *_strtok(char *buffer, const char *delim)
{
	static char *sp;
	char *p;
	int letter = 0;
	int i = 0;
	int stop = 0;

	if (buffer)
		sp = buffer;
	p = sp;
	while (sp && *sp)
	{
	while (delim[i])
	{
	if (*sp == delim[i] && letter == 0)
	{
	++p;
	++sp;
	i = 0;
	continue;
	}
	if (*sp == delim[i] && letter == 1)
	{
	*sp++ = '\0';
	stop = 1;
	i = 0;
	break;
	}
	++i;
	}
	if (stop || !*sp)
	break;
	letter = 1;
	i = 0;
	++sp;
	}
	if (!p || *p == '\0')
	return (NULL);
	return (p);
}
