#include "shell.h"

/**
 * check_path - searche the PATH for directory of commands
 * @build: input builds
 * Returns: true or false
 */
bool check_path(vars_t *build)
{
	register int len;
	static char buffer[BUFSIZE];
	struct stat st;
	char *tok, *copy, *delim = ":", *tmp;
	bool inLoop = false;

	if (check_edge_cases(build))
	return (true);
	copy = _strdup(build->path);
	tok = _strtok(copy, delim);
	while (tok)
	{
	tmp = inLoop ? tok - 2 : tok;
	if (*tmp == 0 && stat(build->args[0], &st) == 0)
	{
	build->fpath = build->args[0];
	free(copy);
	return (true);
	}
	len = _strlen(tok) + _strlen(build->args[0]) + 2;
	_strcat(buffer, tok);
	_strcat(buffer, "/");
	_strcat(buffer, build->args[0]);
	insertNullByte(buffer, len - 1);
	if (stat(buffer, &st) == 0)
	{
	free(copy);
	build->fpath = buffer;
	return (true);
	}
	insertNullByte(buffer, 0);
	tok = _strtok(NULL, delim);
	inLoop = true;
	}
	build->fpath = build->args[0];
	free(copy);
	return (false);
}

/**
 * check_edge_cases - helpers functions for checking  path to check edge cases
 * @build: input build
 * Return: true if found, false if not
 */
bool check_edge_cases(vars_t *build)
{
	char *copy;
	struct stat st;

	copy = _strdup(build->path);
	if (!copy)
	{
	build->fpath = build->args[0];
	free(copy);
	return (true);
	}
	if (*copy == ':' && stat(build->args[0], &st) == 0)
	{
	build->fpath = build->args[0];
	free(copy);
	return (true);
	}
	free(copy);
	return (false);
}
