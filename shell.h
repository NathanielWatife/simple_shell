#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/wait.h>

#define FREE(x) (x = (free(x), NULL))
#define PROMPT " $ "

typedef struct order
{
	unsigned int n;
	struct order *next;
} order_t;

typedef struct env_list
{
	char *name;
	char *value;
	struct env_list *next;
} env_list_t;

int _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _atoi(char *s);
int _strlen(char *str);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strtok(char *buffer, const char *delim);
char *_strchr(char *s, char c);
void _puts(char *str);
void puts_prompt(void);
int _putchar(char c);
void _puts_int(int n);
int MATH_pow(int base, int exp);
int cmd_handler(char **argv, env_list_t **env);
int built_in_handler(char **argv, env_list_t **env, int i);
int _cd(char **argv, env_list_t **env);
void do_nothing(int nothing);
char **get_tokens(char *str_tok, char *delim);
int isin_dir(char *term, char *dir);
char *whitcher(char *cmd, env_list_t **env);
void rem_comments(char *str);
void double_free(char **argv);
char **_initenv(void);
void _setenv(char **argv, char ***env);
void _unsetenv(char *entry, char ***env);
char *_getenv(char *entry, char ***env);
void _printenv(char ***env);
env_list_t **_initenv_list(void);
void printenv_list(env_list_t **env);
char *_getenv_list_value(char *name, env_list_t **env);
env_list_t *_getenv_list_node(char *name, env_list_t **env);
void _setenv_list(char **argv, env_list_t **env);
void free_env_list_node(env_list_t *node);
void _unsetenv_list(char **argv, env_list_t **env);
void free_env_list(env_list_t **env);
char **_get_str_env(env_list_t **env);
void *op_push_end(order_t **ops, int n);
char **_get_cmds(char *line, order_t **ops);
void free_ops(order_t **ops);
extern char **environ;
extern int *LINE_COUNT;
extern char **FNC_NAME;
extern char **environ;
char *_getline(void);
char **_splitline(char *line_buf);
int _execute(char **args, int *flag, int mode);
char *_pathfinder(char *command, int mode);
char *_catpath(char **uncatpath, char *command);
int _builtins(char **args);
void _cd(char **args);
void _env(void);
/*Utilities*/
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strcmp_path(char *s1, char *s2);
unsigned int _strcspn(char *s, char *pre);
int _strspn(char *s, const char *delim);
void _nonintmode(char *line, char **args);
char *_strchr(char *s, char b);
/*Proto-Functions*/
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char *_strtok_r(char *s, const char *delim, char **save_str);
char *_strtok(char *s, char *deli);
#endif
