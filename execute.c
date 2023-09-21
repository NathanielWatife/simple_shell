#include "shell.h"

/**
 * _execute - Executes the given command and certain flags
 * @args: The issued command
 * @flag: Flags out if the command was fully written or needs pathfinding
 * @mode: Flag to select the mode, interactive or inninterative
 * Return: Returns a status, 1 to continue and 0 to stop
**/
int _execute(char **args, int *flag, int mode)
{
	pid_t pid;
	int status;
	int builtstatus = 0;
	int k = 0;
	int flagfinder = 0;

	if (args == NULL)
		return (1);
	builtstatus = _builtins(args);
	if (builtstatus < 2)
		return (builtstatus);
	for (k = 0; *(args[0] + k) != '\0'; k++)
	{
		if (*(args[0] + k) == '/')
		{
			flagfinder = 1;
			break;
		}
	}
	if (flagfinder == 0)
	{
		args[0] = _pathfinder(args[0], mode);
		*flag = 1;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("ERROR: Couldn't execute program");
			free(args[0]);
			free(args);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		perror("ERROR: Child couldn't be created");
	else
		wait(&status);
return (1);
}
