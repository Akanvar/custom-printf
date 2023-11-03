#include "shell.h"
/**
 * myPrintf - prints out characters
 * @cmdString: command coming in to be printed
 * Return: void
 */
void myPrintf(const char *cmdString)
{
	write(STDOUT_FILENO, cmdString, strlen(cmdString));
}

