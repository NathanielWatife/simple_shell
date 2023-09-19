#include "shell.h"

/**
  * _cd - change directory
  * @argv: argument vector
  * @env: environment linked list
  */
int _cd(char **argv, env_list_t **env)
{
	char buf[BUFSIZ]; /* BUFSIZ is predefined~8k */
	char *home = _getenv_list_value("HOME", env);
	char *old = _getenv_list_value("OLDPWD", env);
	char **OLDPWD = malloc(sizeof(char *) * 4);
	char **PWD = malloc(sizeof(char *) * 4);
	DIR *dir;

	OLDPWD[0] = "";
	OLDPWD[1] = "OLDPWD";
	OLDPWD[2] = buf;
	OLDPWD[3] = NULL;
	PWD[0] = "";
	PWD[1] = "PWD";
	PWD[2] = buf;
	PWD[3] = NULL;
	getcwd(buf, sizeof(buf));
	if (argv[1])
	{
		dir = opendir(argv[1]);
		if (dir)
		{
			closedir(dir);
			chdir(argv[1]);
		}
		else if (!_strcmp(argv[1], "~"))
			chdir(home);
		else if (!_strcmp(argv[1], "-"))
		{
			if (!old)
			{
				_puts(*FNC_NAME);
				_puts(": ");
				_puts_int(*LINE_COUNT);
				_puts(": can't cd to ");
				_puts(argv[1]);
				_putchar('\n');
				free(OLDPWD);
				free(PWD);
				return (1);
			}
			else
				chdir(old);
		}
		else
		{
			_puts(*FNC_NAME);
			_puts(": ");
			_puts_int(*LINE_COUNT);
			_puts(": can't cd to ");
			_puts(argv[1]);
			_putchar('\n');
			free(OLDPWD);
			free(PWD);
			return (1);
		}
	}
	else
		chdir(home);
	_setenv_list(OLDPWD, env);
	getcwd(buf, sizeof(buf));
	_setenv_list(PWD, env);
	free(OLDPWD);
	free(PWD);
	return (0);
}
