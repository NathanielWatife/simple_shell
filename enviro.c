#include "shell.h"

/**
 * env_func - prints the enviroment
 * @build: input build
 * Return: Always 1
 */
int env_func(vars_t *build)
{
	printList(build->enviroment);
	return (1);
}

/**
 * setenvFunc - adds env variable if it does not exist;
 * modify env variable if it does
 * @build: input build
 * Return: Always 1
 */
int setenvFunc(vars_t *build)
{
	register int index, len;
	static char buffer[BUFSIZE];

	if (count_args(build->args) != 3)
	{
	errno = EWSIZE;
	errorHandler(build);
	return (1);
	}
	len = _strlen(build->args[1]) + _strlen(build->args[2]) + 2;
	_strcat(buffer, build->args[1]);
	_strcat(buffer, "=");
	_strcat(buffer, build->args[2]);
	insertNullByte(buffer, len - 1);
	index = searchNode(build->enviroment, build->args[1]);
	if (index == -1)
	{
	addNodeEnd(&build->enviroment, buffer);
	insertNullByte(buffer, 0);
	return (1);
	}
	deleteNodeAtIndex(&build->enviroment, index);
	addNodeAtIndex(&build->enviroment, index, buffer);
	insertNullByte(buffer, 0);
	return (1);
}

/**
 * unsetenvFunc - deletes env variable if exists;
 * will only accept valid variables names
 * @build: input build
 * Return: Always 1
 */
int unsetenvFunc(vars_t *build)
{
	register int foundVar, i = 1;
	bool foundMatch = false;

	while (build->args[i])
	{
	if (_isalpha(build->args[i][0]) || build->args[i][0] == '_')
	{
	foundVar = searchNode(build->enviroment, build->args[i]);
	if (foundVar > -1)
	{
	deleteNodeAtIndex(&build->enviroment, foundVar);
	foundMatch = true;
	}
	}
	i++;
	}
	if (foundMatch == false)
	{
	errno = ENOSTRING;
	errorHandler(build);
	}
	return (1);
}

/**
 * _isalpha - checks if c is an alphabetic character
 * @c: potential alphabetical value
 * Return: if c is a letter, returns 1. Otherwise, return 0.
 */
int _isalpha(int c)
{
	if (c > 64 && c < 91)
	return (1);
	else if (c > 96 && c < 123)
	return (1);
	else
	return (0);
}
