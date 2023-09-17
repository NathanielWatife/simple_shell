#include "shell.h"
/**
 * _signal - block signal of Ctrl + C
 * @s: signal to verify
 * Return: Always 0.
 */
void _signal(int s)
{
	(void)s;
	write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}
/**
 * execute - evaluate the input and execute the program
 * depending arguments
 * @input: Pointer to pointer arguments
 * Return: 0 is success or -1 is error
 */
int execute(char *input)
{
	int k = 0;
	int stat = 0;
	char **argv;

	if (_strcmp(input, "env\n") == 0)
	{
	print_env();
	return (0);
	}
	else
	{
	argv = do_arguments(input);
	if (argv[0][0] == '/' || argv[0][0] == '.')
	stat = execve(argv[0], argv, NULL);
	else
	stat = execute_path(argv[0], argv);
	}
	while (argv[k] != NULL)
	{
	free(argv[k]);
	k++;
	}
	free(argv);
	return (stat);
}
/**
 * print_env - print the environment variables
 */
void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
	dprintf(1, "%s\n", environ[i]);
	i++;
	}
}
