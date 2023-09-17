#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>
#include <stddef.h>
#include <string.h>
/**
 * struct path - singly linked list
 * @path: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Shell project
 */
typedef struct path
{
	char *path;
	struct path *next;
} path_t;
void _signal(int s);
void shell_loop(char **argv);
size_t _getline(char **buffer, size_t *n);
int execute(char *input);
int _strcmp(char *s1, char *s2);
path_t *add_path(path_t **head, const char *str);
void free_list(path_t *head);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_getenv(const char *name);
path_t *do_link();
char *_strcat(char *dest, char *src);
void print_env(void);
int execute_path(char *exec, char **options);
void write_error(char *name, char **buffer, size_t nerrors);
char **do_arguments(char *input);
char *_strtok(char *str, char *tokens);
int val_spaces(char *buffer);
#endif
