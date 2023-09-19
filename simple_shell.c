#include "shell.h"

int line_count = 1;
int *LINE_COUNT = &line_count;
char *fnc_name;
char **FNC_NAME = &fnc_name;
/**
  * main - entry point
  * @ac: arg count
  * @av: arg vector
  * Return: 0
  */
int main(__attribute__((unused))int ac, char **av)
{
	int exit_status = 0, last_return = 0, i;
	size_t line_size = 0;
	ssize_t getline_size;
	char **argv, *line = NULL, **argvv;
	env_list_t **env;
	order_t **ops = malloc(sizeof(order_t *));
	order_t *a;

	*FNC_NAME = av[0];
	env = _initenv_list();
	signal(SIGINT, do_nothing);
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			puts_prompt();
		getline_size = getline(&line, &line_size, stdin);
		if (getline_size == -1)
		{
			free(line);
			free_env_list(env);
			free_ops(ops);
			if (isatty(STDIN_FILENO) == 1)
				_putchar('\n');
			return (last_return);
		}
		line[getline_size - 1] = '\0';

		rem_comments(line);

		*ops = NULL;
		argvv = _get_cmds(line, ops);

		a = *ops;
		for (i = 0; argvv[i]; i++)
		{
			argv = get_tokens(argvv[i], " ");
			if (argv[0])
			{
				if (!_strcmp(argv[0], "exit"))
				{
					if (argv[1])
						exit_status = _atoi(argv[1]);
					else
						exit_status = last_return;
					free(line);
					free_env_list(env);
					free_ops(ops);
					free(argvv);
					free(argv);
					exit(exit_status);
				}

				last_return = cmd_handler(argv, env);
			}
			else
				last_return = 0;
			*LINE_COUNT += 1;
			/* balance malloc() from get_tokens_strtok.c:26 */
			FREE(argv);
			if (a)
			{
				if (!last_return && a->n == 3)
				{
					i++;
				}
				if (last_return && a->n == 2)
				{
					i++;
				}
				a = a->next;
			}
		}
		free(argvv);
	}
	return (0);
}
