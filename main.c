#include "shell.h"
/**
 * main - start the shell
 * @argc: Counter of arguments received
 * @argv: Pointer to arguments received
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	(void)argc;
	shell_loop(argv);
	return (0);
}
