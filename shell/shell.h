#ifndef SHELL_H
#define SHELL_H
/*
 *The kjxjhcjxh
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
/**
 *
 */

typedef struct list
{
	char *str;
	struct list *next;
} list_t;
/**
 *
 */

typedef struct
{
	list_t *env;
	char *path;
} info_t;

void show_prompt(void);
void myPrintf(const char *cmdString);
void userCMD(char *cmdString, size_t size);
void exeCMD(const char *cmdString);
char *find_path(info_t *info, char *pathstr, char *cmd);
int is_cmd(info_t *info, char *path);
char *dup_chars(char *pathstr, int start, int stop);

#endif /* SHELL_H */
