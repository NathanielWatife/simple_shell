#include "shell.h"

/**
 * free_members - frees build vars_t members
 * @build: input build
 */
void free_members(vars_t *build)
{
	if (build->enviroment)
	free_list(build->enviroment);
	if (build->args)
	free_args(build->args);
	if (build->buffer)
	free(build->buffer);
}

/**
 * free_args_and_auffer - frees args and buffer
 * @build: input build
 */
void free_args_and_buffer(vars_t *build)
{
	free_args(build->args);
	free(build->buffer);
}

/**
 * free_list - frees a linked list
 * @head: double pointer to head of list
 */
void free_list(lin_t *head)
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
 * free_args - helper func that frees double pointer arg
 * @args: array of char pointers
 */
void free_args(char **args)
{
	register uint i = 0;

	while (args[i])
	free(args[i++]);
	free(args);
}
