#include "shell.h"

/**
 * shell - simple shell
 * @build: input build
 */
void shell(vars_t *build)
{
	while (true)
	{
		checkAndGetLine(build);
		if (splitString(build) == false)
			continue;
		if (findinborns(build) == true)
			continue;
		checkPath(build);
		forkAndExecute(build);
	}
}

/**
 * checkAndGetLine - check stdin and retrieves next line; handles
 * prompt display
 * @build: input build
 */
void checkAndGetLine(vars_t *build)
{
	register int len;
	size_t bufferSize = 0;
	char *ptr, *ptr2;

	build->args = NULL;
	build->enviromentList = NULL;
	build->count++;
	if (isatty(STDIN_FILENO))
		displayPrompt();
	len = getline(&build->buffer, &bufferSize, stdin);
	if (len == EOF)
	{
		freeMembers(build);
		if (isatty(STDIN_FILENO))
			displayNewLine();
		if (build->error)
			exit(build->error);
		exit(EXIT_SUCCESS);

	}
	ptr = _strchr(build->buffer, '\n');
	ptr2 = _strchr(build->buffer, '\t');
	if (ptr || ptr2)
		insertNullByte(build->buffer, len - 1);
	stripComments(build->buffer);
}

/**
 * stripComments - remove comments from input string
 * @str: input string
 * Return: length of remaining string
 */
void stripComments(char *str)
{
	register int i = 0;
	bool notFirst = false;

	while (str[i])
	{
		if (i == 0 && str[i] == '#')
		{
			insertNullByte(str, i);
			return;
		}
		if (notFirst)
		{
			if (str[i] == '#' && str[i - 1] == ' ')
			{
				insertNullByte(str, i);
				return;
			}
		}
		i++;
		notFirst = true;
	}
}

/**
 * forkAndExecute - fork current build and execute processes
 * @build: input build
 */
void forkAndExecute(vars_t *build)
{
	int status;
	pid_t f1 = fork();

	convertLLtoArr(build);
	if (f1 == -1)
	{
		perror("error\n");
		freeMembers(build);
		freeArgs(build->enviromentList);
		exit(1);
	}
	if (f1 == 0)
	{
		if (execve(build->fpath, build->args, build->enviromentList) == -1)
		{
			errorHandler(build);
			freeMembers(build);
			freeArgs(build->enviromentList);
			if (errno == ENOENT)
				exit(127);
			if (errno == EACCES)
				exit(126);
		}
	} else
	{
		wait(&status);
		if (WIFEXITED(status))
			build->error = WEXITSTATUS(status);
		freeArgsAndBuffer(build);
		freeArgs(build->enviromentList);
	}
}

/**
 * convertLLtoArr - convert linked list to array
 * @build: input build
 */
void convertLLtoArr(vars_t *build)
{
	register int i = 0;
	size_t count = 0;
	char **enviromentlist = NULL;
	lin_t *tmp = build->enviroment;

	count = list_len(build->enviroment);
	enviromentlist = malloc(sizeof(char *) * (count + 1));
	if (!enviromentlist)
	{
		perror("Malloc failed\n");
		exit(1);
	}
	while (tmp)
	{
		enviromentlist[i] = _strdup(tmp->str);
		tmp = tmp->nxt;
		i++;
	}
	enviromentlist[i] = NULL;
	build->enviromentList = enviromentlist;
}
