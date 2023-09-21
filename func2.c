#include "shell.h"

/**
 * search_node - searches linked list for string and
 * returns index
 * @head: pointer to head of list
 * @str: input string
 * Return: index of node with matching string
 */
int search_node(lin_t *head, char *str)
{
	register int len = 0, index = 0, i;
	lin_t *current;
	char *tmp, *ptr;

	current = head;
	while (current)
	{
	ptr = _strchr(current->str, '=');
	len = ptr - current->str;
	tmp = malloc(sizeof(char) * len + 1);
	for (i = 0; i < len; i++)
	tmp[i] = current->str[i];
	tmp[i] = '\0';
	if (_strcmp(str, tmp) == 0)
	{
	free(tmp);
	return (index);
	}
	index++;
	current = current->nxt;
	free(tmp);
	}
	return (-1);
}

/**
 * generateLinkedList - generates a linked list of environ
 * variables
 * @array: input array of strings
 * Return: head of linked list
 */
lin_t *generateLinkedList(char **array)
{
	register int i = 0;
	lin_t *head;

	head = NULL;
	while (array[i])
	{
	addNodeEnd(&head, array[i]);
	i++;
	}
	return (head);
}

/**
 * addNodeAtIndex - add node at index with string
 * @head: double pointer to head
 * @index: index to add at
 * @str: string to add
 * Return: address of node added
 */
lin_t *addNodeAtIndex(lin_t **head, int index, char *str)
{
	register int i = 0;
	lin_t *newNode, *current;
	char *newStr;

	current = *head;
	if (!str)
	return (NULL);
	newNode  = malloc(sizeof(lin_t));
	if (!newNode)
	{
	perror("Malloc failed\n");
	exit(errno);
	}
	newStr = _strdup(str);
	if (!newStr)
	{
	free(newNode);
	perror("Malloc failed\n");
	exit(errno);
	}

	newNode->str = newStr;
	newNode->nxt = NULL;

	while (i < index - 1)
	{
	if (current->nxt == NULL)
	{
	free(newNode);
	return (NULL);
	}
	current = current->nxt;
	i++;
	}
	newNode->nxt = current->nxt;
	current->nxt = newNode;
	return (newNode);
}

/**
 * getNodeAtIndex - returns the nth node of a listint_t linked list
 * @head: pointer to head of list
 * @index: index of value to be returned
 * Return: address of node at input index
 */
char *getNodeAtIndex(lin_t *head, unsigned int index)
{
	register uint count = 0;
	lin_t *current;
	char *ptr;

	current = head;
	while (current)
	{
	if (count == index)
	{
	ptr = _strdup(current->str);
	return (ptr);
	}
	count++;
	current = current->nxt;
	}
	return (NULL);
}
