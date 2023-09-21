#include "shell.h"

/**
 * _strcpy - Swaps integers wih pointers.
 * @dest: is a pointer to a char
 * @src: is a pointer to a char
 * Return: Always 0.
**/
char *_strcpy(char *dest, char *src)
{
	char buff[1025];
	int i = 0, j, pos = 0;

	while (*(src + i) != '\0')
	{
		buff[i] = *(src + i);
		i++;
	}

	for (j = 0; *(src + j) != '\0' ; j++)
	{
		*(dest + pos) = buff[j];
		pos++;
	}

	dest[j] = '\0';
return (dest);
}
