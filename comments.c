#include "shell.h"

/**
  * rem_comments - removes comments from a string.
  * @str: string to have comment surgery.
  */

void rem_comments(char *str)
{
	char *del = _strchr(str, '#');

	if (del)
	*del = '\0';
}
