#include "shell.h"

/**
 * _getenv - retrieves env var that matches input str
 * @input: input str
 * @evn: local environmental var
 * Return: string of env var
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
