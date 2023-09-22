#include "shell.h"

/**
 * findinborns - validates if command is builtin and executes
 * @build: input build
 * Return: true if found, false if not
 */
bool findinborns(vars_t *build)
{
	register int i = 0;
	inborns_t getinborns[] = {
		{"exit", exitFunc},
		{"env", envFunc},
		{"cd", cdFunc},
		{"setenv", setenvFunc},
		{"unsetenv", unsetenvFunc},
		{"help", helpFunc},
		{NULL, NULL}
	};

	while (getinborns[i].cmd)
	{
		if (_strcmp(build->args[0], getinborns[i].cmd) == 0)
		{
			getinborns[i].func(build);
			freeArgsAndBuffer(build);
			return (true);
		}
		i++;
	}
	return (false);
}

/**
 * exitFunc - exits the application
 * @build: input build
 * Return: 1 on success, 0 on failure
 */
int exitFunc(vars_t *build)
{
	register int argCount, exitStatus;

	argCount = countArgs(build->args);
	if (argCount == 1)
	{
		freeMembers(build);
		if (build->error)
			exit(build->error);
		exit(EXIT_SUCCESS);
	}
	else if (argCount > 1)
	{
		exitStatus = _atoi(build->args[1]);
		if (exitStatus == -1)
		{
			errno = EILLEGAL;
			build->error = 2;
			errorHandler(build);
			return (0);
		}
		freeMembers(build);
		exit(exitStatus);
	}
	return (1);
}
