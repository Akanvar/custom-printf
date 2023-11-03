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
/*
 *thebse aibfbskf
 */
void show_prompt(void);
void myPrintf(const char *cmdString);
void userCMD(char *cmdString, size_t size);
void exeCMD(const char *cmdString);


#endif /* SHELL_H */
