#include "shell.h"
/**
 * _strcmp - compare a string adding all characters
 * @s1: String one
 * @s2: String two
 * Return: A hash
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int res = 0;

	while (s1[i] != '\0')
	{
	if (s1[i] != s2[i])
	{
	res = (s1[i] - s2[i]);
	break;
	}
	i++;
	}
	return (res);
}
/**
 * _strcat - concatenates two strings
 * @dest: pointer one
 * @src: pointer two
 * Return: A string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i])
	{
	i++;
	}
	while (src[j])
	{
	dest[i] = src[j];
	i++;
	j++;
	if (src[j] == '\0')
	break;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcpy - store a copy of a pointer into another pointer
 * @dest: Pointer one
 * @src: Pointer two
 * Return: Pointer
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
	dest[i] = src[i];
	i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strlen - prints a string
 * @s: This is the string to evaluate
 * Return: Quantity of characters into a string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	i++;
	return (i);
}
/**
 * _strdup - reallocate an array in newly allocated space in memory
 * @str: starter address to reallocate
 * Return: New address of array
 */
char *_strdup(char *str)
{
	char *nstr = NULL;

	if (str == NULL)
	return (NULL);
	nstr = malloc(_strlen(str) + 1);
	if (nstr == NULL)
	return (NULL);
	_strcpy(nstr, str);
	return (nstr);
}
