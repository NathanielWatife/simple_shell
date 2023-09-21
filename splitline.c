#include "shell.h"

/**
 * _splitline - split a char * into char **
 * @line_buf: pointer to be splited
 * Description: split a pointer to char
 * Return: double pointer with split pointer
 * for Holberton project
 */
char **_splitline(char *line_buf)
{
	char **args = NULL;
	int i = 0;
	char *token = NULL;

	if (line_buf == NULL)
		return (NULL);

	args = (char **)malloc(sizeof(char *) * 1024);
	if (args == NULL)
		return (NULL);

	token = _strtok(line_buf, "\t\r\n ");
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = _strtok(NULL, "\t\r\n ");
	}

	args[i] = NULL;
	free(token);
	return (args);
}
