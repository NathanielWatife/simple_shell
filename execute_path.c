#include "shell.h"
/**
 * do_arguments - create pointer to pointer of options
 * of command to execute
 * @input: Command to catch
 * Return: Pointer to pointer of options
 */
char **do_arguments(char *input)
{
	int i = 0, j = 0;
	char *path = input;
	char *tmpexe = _strdup(input);
	char **argv = NULL;

	path = strtok(path, " \n\t");
	while (path != NULL)
	{
	i++;
	path = strtok(NULL, " \n\t");
	}
	argv = (char **) malloc((sizeof(char *) * i) + 1);
	if (argv == NULL)
	{
	free(tmpexe);
	return (NULL);
	}
	tmpexe = strtok(tmpexe, " \n\t");
	while (tmpexe != NULL)
	{
	argv[j] = _strdup(tmpexe);
	j++;
	tmpexe = strtok(NULL, " \n\t");
	}
	argv[i + 1] = NULL;
	free(tmpexe);
	return (argv);
}
/**
 * execute_path - execute the command searching in each directory
 * of PATH variable
 * @name: command to execute
 * @options: options to execute with command
 * Return: 0 is success or -1 is error
 */
int execute_path(char *name, char **options)
{
	DIR *dir;
	int st = 0;
	struct dirent *pDirent;
	path_t *head = do_link();
	path_t *tmp = head;
	char *path = NULL;

	while (tmp->next != NULL)
	{
	dir = opendir(tmp->path);
	if (dir == NULL)
	{
	printf("Cannot open directory '%s'\n", head->path);
	return (1);
	}
	while ((pDirent = readdir(dir)) != NULL)
	{
	if ((_strcmp(pDirent->d_name, name)) == 0)
	{
	path = _strdup(tmp->path);
	path = _strcat(path, "/");
	path = _strcat(path, name);
	options[0] = malloc(_strlen(path) + 1);
	_strcpy(options[0], path);
	break;
	}
	}
	closedir(dir);
	if (path != NULL)
	break;
	tmp = tmp->next;
	}
	if ((execve(path, options, NULL)) == -1)
	st = -1;
	free(path);
	free_list(head);
	return (st);
}
