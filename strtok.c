#include "shell.h"
/**
 * _strtok - splits a string into tokens by delimiters
 * @str: String to split
 * @tokens: Delimiters to do the split
 * Return: pointer with the token
 */
char *_strtok(char *str, char *tokens)
{
	static char *newstr;
	int i = 0, j;

	if (str != NULL)
	{
	for (i = 0; str[i] != '\0'; i++)
	{
	for (j = 0; tokens[j] != '\0'; j++)
	{
	if (str[i] == tokens[j])
	{
	str[i] = '\0';
	newstr = str;
	return (str);
	}
	}
	}
	}
	else
	{
	if (newstr != NULL)
	{
	for (i = 0; newstr[i] != '\0'; i++)
	;
	newstr = &newstr[i + 1];
	for (i = 0; newstr[i] != '\0'; i++)
	{
	for (j = 0; tokens[j] != '\0'; j++)
	{
	if (newstr[i] == tokens[j])
	{
	newstr[i] = '\0';
	return (newstr);
	}
	}
	}
	}
	}
	return (NULL);
}
