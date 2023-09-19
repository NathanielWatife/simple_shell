#include "shell.h"

/**
  * _initenv_list - initialize a env_list
  * Return: env_list_t **, new list formed
  */
env_list_t **_initenv_list(void)
{
	env_list_t **env = malloc(sizeof(env_list_t *));
	env_list_t *head = NULL;
	env_list_t *new_env = NULL;
	char *token;
	int var_count = 0;

	for (var_count = 0; environ[var_count]; var_count++)
	{
	new_env = malloc(sizeof(env_list_t));
	if (head)
	head->next = new_env;
	token = _strdup(_strtok(environ[var_count], "="));
	new_env->name = token;
	token = _strdup(_strtok(NULL, " "));
	new_env->value = token;
	new_env->next = NULL;
	head = new_env;
	if (var_count == 0)
	*env = head;
	}
	return (env);
}

/**
  * printenv_list - prints a env_list
  * @env: environment linked list
  */
void printenv_list(env_list_t **env)
{
	env_list_t *i = *env;

	while (i)
	{
	_puts(i->name);
	_puts("=");
	_puts(i->value);
	_puts("\n");
	i = i->next;
	}
}

/**
  * free_env_list_node - free's an env_list node
  * @node: env_list node to be free'd
  */
void free_env_list_node(env_list_t *node)
{
	free(node->name);
	free(node->value);
	free(node);
}

/**
  * free_env_list - free's an env_list list
  * @env: environment linked list
  */
void free_env_list(env_list_t **env)
{
	env_list_t *temp;

	while (*env)
	{
	temp = *env;
	*env = (*env)->next;
	free_env_list_node(temp);
	}
	free(env);
}
