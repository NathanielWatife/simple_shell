#include "shell.h"

/**
  * isin_dir - checks if term is in the directory given
  * @term: file to be searched for
  * @dir: directory to be searched
  * Return: 1 if true, 0 if false
  */
int isindir(char *term, char *dir)
{
	DIR *folder;
	struct dirent *entry;
	int files = 0;

	folder = opendir(dir);
	if (folder == NULL)
	{
	perror("Unable to read directory");
	return (1);
	}
	while ((entry = readdir(folder)))
	{
	files++;
	if (!_strcmp(entry->d_name, term))
	{
	closedir(folder);
	return (1);
	}
	}
	closedir(folder);
	return (0);
}
