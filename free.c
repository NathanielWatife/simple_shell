#include "shell.h"

/**
  * double_free - free's char * arrays
  * @argv: argument vector.
  */

void double_free(char **argv)
{
	int i;

	for (i = 0; argv[i]; i++)
	{
	free(argv[i]);
	}
	free(argv);
}
