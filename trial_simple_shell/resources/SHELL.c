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
	pid_t pid;

	while (1)
	{ 
		kelm_prompt();
		if (getline(&buff, &n, stdin) == -1)
		{	
			perror("getline");
			exit(EXIT_FAILURE);
		}

		
		token = strtok(buff, " ");
		array = malloc(sizeof(char *));
		if (array == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		while (token)
		{
			array = realloc(array, (i + 1) * sizeof(char *));
                        if (array == NULL)
                        {
                                perror("realloc");
                                exit(EXIT_FAILURE);
                        }
			array[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		array[i - 1][strlen(array[i - 1]) - 1] = '\0';
        	array = realloc(array, (i + 1) * sizeof(char *));
		array[i] = NULL;
		//if (strcmp(array[0], "exit") == 0)
		//	break;
		/*char **new_env = NULL;
    		int x, env_count = 0;
    		while (environ[env_count] != NULL) {
        		env_count++;
    		}
    		new_env = malloc((env_count + 1) * sizeof(char *));
    		for (x = 0; x < env_count; x++) {
        		new_env[x] = strdup(environ[x]);  // Copy each environment variable
    		}
    		new_env[env_count] = NULL;  // Set the last element to NULL */

		const char *path_value = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
		if (setenv("PATH", path_value, 1) != 0)
		{
			perror("setenv");
			exit(EXIT_FAILURE);
		}
		char *path = getenv("PATH");
		if (path == NULL)
		{
			perror("getenv");
			exit(EXIT_FAILURE);
		}
			
		char *path_array = malloc(strlen(path) + 1);
		if (path_array == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		strcpy(path_array, path);

		char *path_token = strtok(path_array, ":");
		char **command_path = malloc(sizeof(char *));
		if (command_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		while (path_token)
		{
			
            		command_path = realloc(command_path, (j + 1) * sizeof(char *));
			if (command_path == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
			command_path[j] = path_token;
			path_token = strtok(NULL, ":");
			j++;
		}
		command_path = realloc(command_path, (j + 1) * sizeof(char *));
		command_path[j] = NULL;

		for (int k = 0; command_path[k] != NULL; k++)
        	{	
			 char *full_path = malloc(strlen(command_path[k]) + strlen(array[0]) + 2);
			 if (full_path == NULL)
			 {
				 perror("malloc");
				 exit(EXIT_FAILURE);
			 }
            		snprintf(full_path, strlen(full_path) + strlen(array[0]) + 2, "%s/%s", command_path[k], array[0]);
			if (access(full_path, F_OK) != -1)
			{
				if ((pid = fork()) == -1)
				{
					perror("error");
					exit(EXIT_FAILURE);
				}

				if (pid == 0)
				{
					if (execve(full_path, array, NULL) == -1)
					{
						perror("error");
						exit(EXIT_FAILURE);
					}
				}
				else
					wait(NULL);
				i = 0;
				j = 0;	
			}
			free(full_path);
		}
		/*for (x = 0; x < env_count; x++)
        		free(new_env[x]);
    		free(new_env);*/
		free(array);
		free(command_path);
		free(path_array);
		//free(buff);

	}

}
