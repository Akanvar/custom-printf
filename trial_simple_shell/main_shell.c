#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
int main() {
	size_t n = 0;
	char *buff = NULL;
	//char *token = NULL;
	//char **tok = NULL;
	/*char **array = NULL;*/
	char full_path[1024];
	pid_t pid;
	char *path_array = NULL;
	char *path = NULL;
	char *path_value = NULL; 
	int token_count;
	char *envVar = NULL;
	int i;
	info_t *info;
	info = malloc(sizeof(info_t));
	if (info == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}   
	info->env = NULL;
	info->env_flag = 0;
	while (1) {
		 _setenv(info, "TERM", "xterm-256color");
		kelm_prompt();
		if (getline(&buff, &n, stdin) == -1) {
			//free(buff);
			exit(EXIT_FAILURE);
		}
		char **tok = _strtok(buff, " ");
		if (strcmp(tok[0], "exit") == 0) {
			free(buff);
			break;
		}
		envVar = "PATH";
		path_value = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
		if (_setenv(info, envVar, path_value) != 0)
			perror("_setenv");
		
		path = _getenv(info, envVar);
		if (path == NULL)
			perror("_getenv");

		path_array = strdup(path);
		if (path_array == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		char **token = _strtok(path_array, ":");
		int x = 0;
		while (token[x]) {
			snprintf(full_path, sizeof(full_path), "%s/%s", token[x], tok[0]);
			char *fp = strdup(full_path);
			if (!fp)
				return -1;
	//		if (access(fp, X_OK) != -1) {
			if (stat(fp, &st) == 0) {
    				if (S_ISREG(st.st_mode)){
					if ((pid = fork()) == -1) {
						perror("error");
						exit(EXIT_FAILURE);
					}
				if (pid == 0) {
					environ = _getenviron(info);
					if (execve(full_path, tok, environ) == -1)
						perror("error");
					exit(EXIT_FAILURE);
				} else {
					wait(NULL);
					break;
				} 
				}
			}
			else
			{
				printf("Error code: %d\n", errno);
				exit(EXIT_FAILURE);
			}	
			x++;
		}	
	}
	free_info(info); 
	return 0;
}

