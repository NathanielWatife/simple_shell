#include "shell.h"

/**
 * _getenv - get a value of a variable
 * @name: Constant with the name of environment variable to search
 * Return: the variable
 */
char *_getenv(const char *name)
{
	int i = 0;
	char *tmp, *ptr;

	while (environ[i] != NULL)
	{
	if (_strcmp((char *)name, environ[i]) == 0)
	{
	tmp = environ[i];
	ptr = strtok(tmp, "=");
	ptr = strtok(NULL, "\0");
	break;
	}
	i++;
	}
	return (ptr);
}
/**
 * add_path - add node of each path at the end
 * @head: Address of linked list
 * @str: String to copy and create node
 * Return: Address of linked list with the new node
 */
path_t *add_path(path_t **head, const char *str)
{
	path_t *tmp;
	path_t *last = *head;

	tmp = malloc(sizeof(path_t));
	if (tmp == NULL)
	return (NULL);
	if (str != NULL)
	tmp->path = _strdup((char *)str);
	else
	tmp->path = "(nil)";
	tmp->next = NULL;
	if (*head == NULL)
	{
	*head = tmp;
	return (tmp);
	}
	while (last->next != NULL)
	last = last->next;
	last->next = tmp;
	return (tmp);
}
/**
 * do_link - creates nodes for directories in path and keep
 * until finish the program
 * Return: linked list with the new node
 */
path_t *do_link()
{
	const char *name = "PATH";
	char *nodevalue;
	path_t *head;

	head = NULL;
	nodevalue = _getenv(name);
	nodevalue = strtok(nodevalue, ":");
	while (nodevalue != NULL)
	{
	add_path(&head, nodevalue);
	nodevalue = strtok(NULL, ":");
	}
	return (head);
}

/**
 * free_list - free the memory of each node in the list
 * @head: Address of the list
 */
void free_list(path_t *head)
{
	path_t *current = head;
	path_t *next;

	while (current != NULL)
	{
	next = current->next;
	free(current->path);
	free(current);
	current = next;
	}
}
