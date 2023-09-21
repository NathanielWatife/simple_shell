#include "shell.h"

/**
 * _handler - Behavior of signals
 * @error: Error ID from signal
**/
void _handler(int error)
{
	switch (error)
	{
	case 2:
		write(1, "\n", 1);
		write(STDOUT_FILENO, "$ ", 2);
		break;
	default:
		write(2, "Issued command \n", 15);
		break;
	}
}

/**
 * _nonintmode - No interactive mode, doesn`t open prompt and executes one time
 * @line: Typed command by user sent to splitline
 * @args: Splitted command sent or not no pathfinder and then, executed
 * Return: 1 if completed 0 if failed
**/
void _nonintmode(char *line, char **args)
{
	int status = 1, j = 0;
	size_t len = 0;

	while (getline(&line, &len, stdin) != EOF)
	{
		args = _splitline(line);
		if (args[0] != NULL)
			status = _execute(args, &j, 1);
		if (status == 0)
			if (j == 1)
				free(args[0]);
		free(args);
	}
	free(line);
}
/**
 * main - Loop for shell
 * 1. It receives a command typed by the user in the prompt (_getline)
 * 2. Command is then stored in line.
 * 3. line is sent to splitline to split every argument typed (_splitline)
 * 4. The splitted line is then stored in args, if args is not the full path
 * of the command, then it searches for it (_pathfinder) and is executed
 * (_execute), if args is the full path of the command, it executes
 * 5. The execution returns a status number, it's stored in status
 * if status is 1, the loop goes to the begginning, otherwise, it breaks.
 * Return: void.
**/
int main(void)
{
	char *line = NULL;
	char **args = NULL;
	int status = 1, j;

	signal(SIGINT, _handler);
	if (isatty(STDIN_FILENO) != 1)
		_nonintmode(line, args);
	else
	{
		do {
			j = 0;
			write(STDOUT_FILENO, "$ ", 2);
			line = _getline();
			if (line == NULL)
				break;
			args = _splitline(line);
			if (args[0] != NULL)
				status = _execute(args, &j, 0);
			if (status == 0)
				free(line);
			if (j == 1)
				free(args[0]);
			else
				if (status != 0)
					free(line);
			free(args);
		} while (status);
	}
	return (0);
}
