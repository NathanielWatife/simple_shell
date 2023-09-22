#include "shell.h"

/**
 * cdFunc - execute cd builtin
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int cdFunc(vars_t *build)
{
	register uint count = 0;
	bool ableToChange = false;

	count = countArgs(build->args);
	if (count == 1)
		ableToChange = cdToHome(build);
	else if (count == 2 && _strcmp(build->args[1], "-") == 0)
		ableToChange = cdToPrevious(build);
	else
		ableToChange = cdToCustom(build);
	if (ableToChange)
		updEnviron(build);
	return (1);
}

/**
 * cdToHome - change directory to home
 * @build: input build
 * Return: true on success, false on failure
 */
bool cdToHome(vars_t *build)
{
	register int i;
	char *str, *ptr;

	i = searchNode(build->enviroment, "HOME");
	if (i == -1)
	{
		return (true);
	}
	str = getNodeAtIndex(build->enviroment, i);
	ptr = _strchr(str, '=');
	ptr++;
	chdir(ptr);
	free(str);
	return (true);
}

/**
 * cdToPrevious - change directory to previous directory -
 * address is found in OLDPWD enviroment var
 * @build: input build
 * Return: true on success, false on failure
 */
bool cdToPrevious(vars_t *build)
{
	register int i;
	char *str, *ptr;
	char *current = NULL;

	current = getcwd(current, 0);
	i = searchNode(build->enviroment, "OLDPWD");
	if (i == -1)
	{
		chdir(current);
		write(STDOUT_FILENO, current, _strlen(current));
		displayNewLine();
		return (true);
	}
	str = getNodeAtIndex(build->enviroment, i);
	ptr = _strchr(str, '=');
	ptr++;
	chdir(ptr);
	write(STDOUT_FILENO, ptr, _strlen(ptr));
	displayNewLine();
	free(str);
	return (true);
}

/**
 * cdToCustom - change directory to what user inputs in
 * @build: input build
 * Return: true on success, false on failure
 */
bool cdToCustom(vars_t *build)
{
	register int changeStatus;

	changeStatus = chdir(build->args[1]);
	if (changeStatus == -1)
	{
		errno = EBADCD;
		errorHandler(build);
		return (false);
	}
	return (true);
}
