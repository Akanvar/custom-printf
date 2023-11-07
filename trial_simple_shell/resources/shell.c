#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "shell.h"

int main()
{
	size_t n;
	char *buff = NULL;
	char *token;
	char **array;
	int i = 0;
	pid_t pid;

	while (1)
	{ 
		kelm_prompt();
		if (getline(&buff, &n, stdin) == -1)
			break;

		token = strtok(buff, "\t\n");
		array = malloc(sizeof(char *) * 1024);

		while (token)
		{
			array[i] = token;
			token = strtok(NULL, "\t\n");
			i++;
		}
			array[i] = NULL;
			if ((pid = fork()) == -1)
			{
				perror("error");
				exit(EXIT_FAILURE);
			}

		if (pid == 0)
		{
			if (execve(array[0], array, NULL) == -1)
				perror("error");
		}
		else
			wait(NULL);
		i = 0;
		free(array);
	}
}
