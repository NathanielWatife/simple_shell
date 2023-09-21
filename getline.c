 #include "shell.h"

/**
 * _getline - Receives a command typed by the user in the prompt
 * Return: Returns the typed command
**/
char *_getline(void)
{
	char *line = NULL;
	size_t len = 0;
	int read = 0;

	read = getline(&line, &len, stdin);
	if (read != -1)
		return (line);
	free(line);
	write(1, "\n", 1);
	return (NULL);
}
