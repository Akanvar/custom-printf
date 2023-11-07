#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "shell.h"

int main()
{
	size_t n = 0;
	char *buff = NULL;
	char *token;
	char **array;
	int i = 0, j = 0;
	char full_path[1024];
	pid_t pid;

	while (1)
	{ 
		kelm_prompt();
		getline(&buff, &n, stdin);

		token = strtok(buff, " ");
		array = malloc(sizeof(char *) * strlen(token));

		while (token)
		{
			array[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		array[i] = NULL;
		if (strcmp(array[0], "exit") == 0)
			break;
		char path_value[1024] = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
		if (setenv("PATH", path_value, 1) != 0)
			perror("setenv");
		char *path = getenv("PATH");
		if (path == NULL)
			perror("getenv");
		char path_array[1024];
		strncpy(path_array, path, sizeof(path_array) - 1);
		char *path_token = strtok(path_array, ":");
		char **command_path = malloc(sizeof(char) * strlen(path_token));
		while (path_token)
		{
			command_path[j] = path_token;
			path_token = strtok(NULL, ":");
			snprintf(full_path, sizeof(full_path), "%s/%s", command_path[j], array[0]);
			j++;
		}
		command_path[j] = NULL;
		if (access(full_path, F_OK) != -1)
		{
			if ((pid = fork()) == -1)
			{
				perror("error");
				exit(EXIT_FAILURE);
			}

			if (pid == 0)
			{
				if (execve(full_path, array, environ) == -1)
					perror("error");
			}
			else
				wait(NULL);
			i = 0;
			j = 0;
			free(array);
			free(command_path);
		}
	}
}
