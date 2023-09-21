#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
/*Functions*/
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
