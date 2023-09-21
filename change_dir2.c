#include "shell.h"

/**
 * upd_nviron - change enviroment variables
 * @build: input build
 * Return: true on success false on failure
 */
bool upd_environ(vars_t *build)
{
	register int i;

	i = upd_old(build);
	upd_cur(build, i);
	return (true);
}

/**
 * upd_old - updates OLDPWD to current PWD
 * @build: input build
 * Return: index in linked list of PWD on success -
 * If PWD or OLDPWD does not exist in evn vars,
 * return -1
 */
int upd_old(vars_t *build)
{
	register int pwdIndex = 0, index = 0;
	static char old[BUFSIZE];
	char *current = NULL;

	_strcat(old, "OLD");
	pwdIndex = searchNode(build->enviroment, "PWD");
	if (pwdIndex == -1)
	{
	return (-1);
	}
	current = getNodeAtIndex(build->enviroment, pwdIndex);
	_strcat(old, current);
	insertNullByte(old, _strlen(current) + 4);
	free(current);
	index = searchNode(build->enviroment, "OLDPWD");
	if (index == -1)
	{
	return (-1);
	}
	deleteNodeAtIndex(&build->enviroment, index);
	addNodeAtIndex(&build->enviroment, index, old);
	insertNullByte(old, 0);
	return (pwdIndex);
}

/**
 * upd_cur - updates PWD to accurately reflect current directory
 * @build: input build
 * @index: index in linked list of where to insert PWD enviroment var
 * Return: true on success, false on failure
 */
bool upd_cur(vars_t *build, int index)
{
	static char tmp[BUFSIZE], cwd[BUFSIZE];

	getcwd(tmp, BUFSIZE);
	_strcat(cwd, "PWD=");
	_strcat(cwd, tmp);
	if (index > -1)
	{
	deleteNodeAtIndex(&build->enviroment, index);
	addNodeAtIndex(&build->enviroment, index, cwd);
	}
	else
	addNodeAtIndex(&build->enviroment, 0, cwd);
	insertNullByte(tmp, 0);
	insertNullByte(cwd, 0);
	return (true);
}
