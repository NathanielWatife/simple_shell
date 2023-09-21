#include "shell.h"

/**
 * _strcat - This function concatenates two strings.
 * @dest: is a pointer to a char.
 * @src: is a pointer to a char.
 * Return: Always 0.
**/

char *_strcat(char *dest, char *src)
{
	int i = _strlen(dest);
	int j;

	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];

	dest[i + j] = '\0';

return (dest);
}
