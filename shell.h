#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <limits.h>

/* ERRORS */
#define BUFSIZE 256
#define ENOSTRING 1106
#define EILLEGAL 227
#define EWSIZE 410
#define ENOBUILTIN 415
#define EBADCD 726

extern char **environ;

/**
 * struct linlist - linked list data structure
 * @str: environ variable path name
 * @nxt: pointer to nxt node
 */
typedef struct linlist
{
	char *str;
	struct linlist *nxt;
} lin_t;

/**
 * struct variables - variables of build settings
 * @enviroment: linked list of local enviroment variables
 * @enviromentList: array of enviroment variables to put into execve
 * @args: array of argument strings
 * @buffer: string buffer of user input
 * @path: array of $PATH locations
 * @fpath: string of path with correct prepended $PATH
 * @shellName: name of shell (argv[0])
 * @count: counter of lines users have entered
 * @error: error status of last child process
 */
typedef struct variables
{
	lin_t *enviroment;
	char **enviromentList;
	char **args;
	char *buffer;
	char *path;
	char *fpath;
	char *shellName;
	unsigned int count;
	int error;
} vars_t;

/**
 * struct inborns - cmds and functions associated with it
 * @cmd: input cmd
 * @func: output function
 */
typedef struct inborns
{
	char *cmd;
	int (*func)(vars_t *build);
} inborns_t;

/* main */
vars_t *vars_tInit(vars_t *build);

/* built_ins */
bool findinborns(vars_t *build);
int exitFunc(vars_t *build);

/* cd */
int cdFunc(vars_t *);
bool cdToHome(vars_t *build);
bool cdToPrevious(vars_t *build);
bool cdToCustom(vars_t *build);
bool updEnviron(vars_t *build);

/* cd2 */
int updold(vars_t *build);
bool updcur(vars_t *build, int index);

/* env */
int envFunc(vars_t *build);
int setenvFunc(vars_t *build);
int unsetenvFunc(vars_t *build);
int _isalpha(int c);

/* help */
int helpFunc(vars_t *build);
int helpmenu(void);
int helpExit(vars_t *build);
int helpEnv(vars_t *build);


/* help2 */

int helpCd(vars_t *biuld);
int helpSetenv(vars_t *build);
int helpUnsetenv(vars_t *build);
int helpHelp(vars_t *build);

/* built_in_helpers*/
int countArgs(char **args);
int _atoi(char *s);

/* shell */
void shell(vars_t *build);
void checkAndGetLine(vars_t *build);
void forkAndExecute(vars_t *build);
void stripComments(char *str);
void convertLLtoArr(vars_t *build);

/* _getenv */
char *_getenv(char *input, char **environ);

/* error_handler */
void errorHandler(vars_t *build);
unsigned int countDigits(int num);
char *itoa(unsigned int num);
char *getErrorMessage();

/* shell_helpers */
void insertNullByte(char *str, unsigned int index);
void displayPrompt(void);
void displayNewLine(void);
void sigintHandler(int sigint);

/* check_path */
bool checkPath(vars_t *);
bool checkEdgeCases(vars_t *build);

/* split_string */
bool splitString(vars_t *build);
unsigned int countWords(char *s);
bool isSpace(char c);

/* string_helpers1 */
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);

/* string_helpers2 */
char *_strtok(char *str, char *delim);
int _strcspn(char *string, char *chars);
char *_strchr(char *s, char c);

/* llfuncs1 */
lin_t *addNode(lin_t **head, char *str);
lin_t *addNodeEnd(lin_t **head, char *str);
size_t printList(const lin_t *h);
int searchNode(lin_t *head, char *str);
size_t list_len(lin_t *h);

/* llfuncs2 */
int deleteNodeAtIndex(lin_t **head, unsigned int index);
lin_t *generateLinkedList(char **array);
lin_t *addNodeAtIndex(lin_t **head, int index, char *str);
char *getNodeAtIndex(lin_t *head, unsigned int index);

/* _realloc */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);

/* free */
void freeMembers(vars_t *build);
void freeArgsAndBuffer(vars_t *build);
void freeArgs(char **args);
void freeList(lin_t *head);

#endif
