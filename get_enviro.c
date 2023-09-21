#include "shell.h"

/**
 * _getenv - retrieves env variable that matches input string
 * @input: input string
 * @evn: local environmental variables
 * Return: string of env variable
 */
char *_getenv(char *input, char **evn)
{
	register int i = 0;
	char *tok, *right;

	while (evn[i])
	{
	tok = _strtok(evn[i], "=");
	if (_strcmp(tok, input) == 0)
	{
	right = _strtok(NULL, "=");
	return (right);
	}
	i++;
	}
	return (NULL);
}
