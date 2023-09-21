#include "shell.h"

/**
 * _cd - Change directory
 * @args: Typed command (built-in)
 * Return: Void
**/
void _cd(char **args)
{
	int cwdlen = 0, j = 0;
	char cwd[1024];

	if (args[1] == NULL)
		chdir(getenv("HOME"));
	else if (_strcmp(args[1], "-") == 0)
	{
		if (getenv("OLDPWD") == NULL)
			chdir(".");
		else
		{
			chdir(getenv("OLDPWD"));
			getcwd(cwd, sizeof(cwd));
			for (cwdlen = 0; cwd[j] != '\0'; j++)
				cwdlen++;
			cwd[j] = '\n';
			write(1, cwd, cwdlen + 1);
		}
	}
	else
		chdir(args[1]);
}

/**
 * _env - Prints environment
 * Return: Void
**/
void _env(void)
{
	int j = 0, k = 0;

	while (environ[j])
	{
		k = _strlen(environ[j]);
		write(STDOUT_FILENO, environ[j], k);
		write(STDOUT_FILENO, "\n", 1);
		j++;
	}
}

/**
 * _builtins - Innate commands of the shell
 * @args: Typed command (built-in)
 * Return: Returns, 0 to break, 1 to continue and 2 for new prompt
**/
int _builtins(char **args)
{
	int i = 0;
	char *builts[] = {"exit", "cd", "env", NULL};

	while (builts[i])
	{
		if (_strcmp(args[0], builts[i]) == 0)
			break;
		i++;
	}
	switch (i)
	{
	case 0:
		return (0);
	case 1:
		_cd(args);
		return (1);
	case 2:
		_env();
		return (1);
	default:
		return (2);
	}
}
