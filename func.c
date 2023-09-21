#include "shell.h"

/**
 * addNode - adds a new node at the beginning of a lin_t list
 * @head: reference to head of linked list
 * @str: string to be added on new node
 * Return: address of new head;
 */
lin_t *addNode(lin_t **head, char *str)
{
	lin_t *newNode;
	char *newStr;

	if (!str)
	return (NULL);
	newNode = malloc(sizeof(lin_t));
	if (!newNode)
	{
	perror("Malloc failed\n");
	exit(errno);
	}
	newStr = _strdup(str);
	if (!newStr)
	{
	perror("Malloc failed\n");
	exit(errno);
	}
	newNode->str = newStr;
	newNode->nxt = *head;
	*head = newNode;
	return (*head);
}

/**
 * addNodeEnd - adds a new node at the end of a lin_t list;
 * @head: reference to head of list
 * @str: string to be added to linked list
 * Return: address of new node
 */
lin_t *addNodeEnd(lin_t **head, char *str)
{
	lin_t *newNode;
	lin_t *last = *head;
	char *newStr;

	if (!str)
	return (NULL);
	newNode = malloc(sizeof(lin_t));
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
	if (!*head)
	{
	*head = newNode;
	return (newNode);
	}
	while (last->nxt)
	last = last->nxt;
	last->nxt = newNode;
	return (last);
}

/**
 * printList - prints all elements of a lin_t list
 * @h: pointer to head of list
 * Return: number of elements
 */
size_t printList(const lin_t *h)
{
	register int count = 0;

	while (h)
	{
	write(STDOUT_FILENO, h->str, _strlen(h->str));
	displayNewLine();
	h = h->nxt;
	count++;
	}
	return (count);
}

/**
 * deleteNodeAtIndex - deletes the node at index
 * index of a lin_t linked list
 * @head: double pointer to head of list
 * @index: index of node to be deleted
 * Return: 1 if success, -1 if fail
 */
int deleteNodeAtIndex(lin_t **head, unsigned int index)
{
	lin_t *current;
	lin_t *next;

	register uint i;

	if (!head || !(*head))
	return (-1);
	current = *head;
	if (!index)
	{
	*head = current->nxt;
	free(current);
	return (1);
	}
	for (i = 0; current && i < index - 1; i++)
	current = current->nxt;
	if (!current || !(current->nxt))
	return (-1);
	next = current->nxt->nxt;
	free(current->nxt->str);
	free(current->nxt);
	current->nxt = next;
	return (1);
}

/**
 * list_len - returns the number of elements in a linked list
 * @h: head of linked list
 * Return: number of elements in list_t
 */
size_t list_len(lin_t *h)
{
	register unsigned int count = 0;

	while (h)
	{
	h = h->nxt;
	count++;
	}
	return (count);
}
