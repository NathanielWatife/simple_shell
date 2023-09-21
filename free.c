#include "shell.h"

/**
 * freeMembers - frees build vars_t members
 * @build: input build
 */
void freeMembers(vars_t *build)
{
	if (build->enviroment)
	freeList(build->enviroment);
	if (build->args)
	freeArgs(build->args);
	if (build->buffer)
	free(build->buffer);
}

/**
 * freeArgsAndBuffer - frees args and buffer
 * @build: input build
 */
void freeArgsAndBuffer(vars_t *build)
{
	freeArgs(build->args);
	free(build->buffer);
}

/**
 * freeList - frees a linked list
 * @head: double pointer to head of list
 */
void freeList(lin_t *head)
{
	lin_t *current;
	lin_t *tmp;

	if (!head)
	return;
	current = head;
	while (current)
	{
	tmp = current;
	current = tmp->nxt;
	free(tmp->str);
	free(tmp);
	}
	head = NULL;
}

/**
 * freeArgs - helper func that frees double pointer arg
 * @args: array of char pointers
 */
void freeArgs(char **args)
{
	register uint i = 0;

	while (args[i])
	free(args[i++]);
	free(args);
}
