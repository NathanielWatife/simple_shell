#include "shell.h"

/**
  * _getenv_list_value - get's a env_list node's value from a name
  * @name: char * to search for
  * @env: environment linked list
  * Return: char * containing nodes value
  */
char *_getenv_list_value(char *name, env_list_t **env)
{
	env_list_t *i = *env;

	while (i)
	{
	if (!_strcmp(name, i->name))
	{
	return (i->value);
	}
	i = i->next;
	}
	return (NULL);
}

/**
  * _getenv_list_node - get's a env_list node
  * @name: name to search for
  * @env: environment linked list
  * Return: env_list_t * node or NULL
  */
env_list_t *_getenv_list_node(char *name, env_list_t **env)
{
	env_list_t *i = *env;

	while (i)
	{
	if (!_strcmp(name, i->name))
	{
	return (i);
	}
	i = i->next;
	}
	return (NULL);
}

/**
  * _setenv_list - set environment variable in list
  * @argv: argument vector
  * @env: environment linked list
  */
void _setenv_list(char **argv, env_list_t **env)
{
	env_list_t *a, *b;

	if (!argv[1] || !argv[2])
	return;
	a = _getenv_list_node(argv[1], env);
	if (a)
	{
	free(a->value);
	a->value = _strdup(argv[2]);
	return;
	}
	a = *env;
	while (a->next)
	{
	a = a->next;
	}
	b = malloc(sizeof(env_list_t));
	b->name = _strdup(argv[1]);
	b->value = _strdup(argv[2]);
	b->next = NULL;
	a->next = b;
}


/**
  * _unsetenv_list - unset's a env_list var
  * @argv: argument vector
  * @env: environment linked list
  */
void _unsetenv_list(char **argv, env_list_t **env)
{
	env_list_t *a, *b;

	if (!argv[1])
	return;
	a = *env;
	b = *env;
	while (a)
	{
	if (!_strcmp(argv[1], a->name))
	{
	b->next = a->next;
	free_env_list_node(a);
	return;
	}
	b = a;
	a = a->next;
	}
}


/**
  * _get_str_env - converts linked list to str[] for execve
  * @env: environment linked list
  * Return: char **, a char *[] representation of env
  */
char **_get_str_env(env_list_t **env)
{
	env_list_t *a = *env;
	int count = 0, entry_len;
	char **str_env;
	char *entry;

	while (a)
	{
	count++;
	a = a->next;
	}
	str_env = malloc(sizeof(char *) * (count + 1));
	a = *env;
	count = 0;
	while (a)
	{
	entry_len = _strlen(a->name) + _strlen(a->value) + 2;
	entry = malloc(sizeof(char) * entry_len);
	_strcpy(entry, a->name);
	entry = _strcat(entry, "=");
	entry = _strcat(entry, a->value);
	str_env[count] = entry;
	count++;
	a = a->next;
	}
	str_env[count] = NULL;
	return (str_env);
}
