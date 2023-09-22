#include "shell.h"

/**
 * main - entry point for application
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	vars_t build;

	(void)ac;
	signal(SIGINT, sigintHandler);
	vars_tInit(&build);
	build.shellName = av[0];
	shell(&build);
	return (0);
}

/**
 * vars_tInit - initialize member values for vars_t struct
 * @build: input build
 * Return: build with initialized members
 */
vars_t *vars_tInit(vars_t *build)
{
	build->enviroment = generateLinkedList(environ);
	build->enviromentList = NULL;
	build->args = NULL;
	build->buffer = NULL;
	build->path = _getenv("PATH", environ);
	build->fpath = NULL;
	build->count = 0;
	build->shellName = NULL;
	build->error = 0;
	return (build);
}
