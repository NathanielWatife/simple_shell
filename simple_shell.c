#include "shell.h"
/**
 * itoa - converts a number into string
 * @nerrors: Number to cast
 * Return: new pointer with number converted to string
 */
char *itoa(size_t nerrors)
{
	char base[] = "0123456789";
	char *newstr;
	unsigned int len = 0;
	int number = nerrors;

	for (len = 0; nerrors > 0; len++)
	{
	nerrors = nerrors / 10;
	}
	newstr = malloc(sizeof(char) * len);
	if (newstr == NULL)
	return (NULL);
	newstr[len] = '\0';
	do {
	newstr[--len] = base[number % 10];
	number /= 10;
	} while (number != 0);
	return (newstr);
}
/**
 * write_error - write an error when no founds a file or directory
 * @name: name of executable
 * @buffer: address of command searched to execute and no found
 * @nerrors: Number of the error
 */
void write_error(char *name, char **buffer, size_t nerrors)
{
	char *n = itoa(nerrors);

	write(2, name, _strlen(name));
	write(2, ": ", 2);
	write(2, n, _strlen(n));
	write(2, ": ", 2);
	write(2, *buffer, _strlen(*buffer));
	write(2, ": not found\n", 12);
	free(n);
}
/**
 * shell_loop - initialize the infinite loop for shell
 * to evaluate the input of user, and executes.
 * @argv: Pointer to arguments recieved
 */
void shell_loop(char **argv)
{
	int errors = 1;
	int status = 0;
	pid_t child;
	char *buffer = NULL;
	int len = 0;
	size_t lenb = 0;

	while (1)
	{
	if (isatty(0) == 1)
	write(STDOUT_FILENO, "#cisfun$ ", 9);
	signal(SIGINT, _signal), len = getline(&buffer, &lenb, stdin);
	if (((int)len == -1) || (_strcmp(buffer, "exit\n") == 0))
	{
	if ((int)len == -1 && isatty(0) == 1)
	write(1, "\n", 1);
	break;
	}
	if (_strcmp(buffer, "\n") == 0 || val_spaces(buffer) == 0)
	continue;
	child = fork();
	if (child == -1)
	free(buffer), perror("Error:");
	if (child == 0)
	{
	if (execute(buffer) == -1)
	{
	write_error(argv[0], &buffer, errors);
	free(buffer);
	exit(127);
	}
	exit(EXIT_SUCCESS);
	}
	else
	wait(&status), errors++;
	}
	free(buffer);
}
/**
 * val_spaces - validate is buffer contains only spaces
 * @buffer: string to validate
 * Return: 0 is only spaces or 1 is contain something more
 */
int val_spaces(char *buffer)
{
	int i = 0, nspaces = 0;
	int len = _strlen(buffer);

	while (buffer[i] != '\0')
	{
	if (buffer[i] == 32)
	nspaces++;
	i++;
	}
	if (nspaces == (len - 1))
	return (0);
	return (1);
}
