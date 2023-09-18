#include "shell.h"
/**
  * built_in_handler - handles built in fncs.
  * @argv: argument in built.
  * @env: environment linked list.
  * @i: switch for built-ins.
  * Return: 0 if it's successful.
  */
int built_in_handler(char **argv, env_list_t **env, int i)
{
	switch (i)
	{
	case 0:
		return (_cd(argv, env));
	case 1:
		_setenv_list(argv, env);
		break;
	case 2:
		_unsetenv_list(argv, env);
		break;
		case 3:
		printenv_list(env);
		break;
	}
	return (0);
}
/**
  * cmd_handler - handles all commands.
  * @argv: argument vector.
  * @env: environment linked list.
  * Return: 0 on failure, 1 on true.
  */
int cmd_handler(char **argv, env_list_t **env)
{
	char *built_ins[] = {"cd", "setenv", "unsetenv", "env", NULL};
	int i, status, exit_value = 0;
	struct stat st;
	char *path_to_file = NULL;
	pid_t child_pid;
	char **str_env = _get_str_env(env);

	for (i = 0; built_ins[i]; i++)
	{
		if (!_strcmp(built_ins[i], argv[0]))
		{
		exit_value = built_in_handler(argv, env, i);
		double_free(str_env);
		return (exit_value);
		}
	}
	if (stat(argv[0], &st) == 0)
	path_to_file = argv[0];
	else
	{
	path_to_file = whitcher(argv[0], env);
	if (path_to_file)
	{
	path_to_file = _strcat(path_to_file, "/");
	path_to_file = _strcat(path_to_file, argv[0]);
	}
	}
	if (!path_to_file)
	{
		_puts(*FNC_NAME);
		_puts(": ");
		_puts_int(*LINE_COUNT);
		_puts(": ");
		_puts(argv[0]);
		_puts(" not found\n");
		double_free(str_env);
		return (127);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
	perror("Error:");
	return (0);
	}
	if (child_pid == 0)
	{
	if (execve(path_to_file, argv, str_env) == -1)
	perror("Error:");
	exit(0);
	}
	wait(&status);
	exit_value = WEXITSTATUS(status);
	double_free(str_env);
	return (exit_value);
}
