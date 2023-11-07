#include "shell.h"
/**
 * exeCMD - function to execote command
 * @cmdString: command to be executed
 */


void exeCMD(char *cmdString)
{
	int i = 0, j = 0;
	char *pathStr;
	info_t *info;

	pid_t pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		info = malloc(sizeof(info_t));
		if (info == NULL)
		exit(EXIT_FAILURE);



	info->path = strdup("PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin");
		if (info->path == NULL)
			exit(EXIT_FAILURE);

		for (i = 5; info->path[i] != '\0'; i++)
			pathStr[j++] = info->path[i];
		pathStr[j] = '\0';



		char command_path[256];
		command_path[256] = find_path(info, pathStr, cmdString);
		if (command_path  == NULL)
			exit(EXIT_FAILURE);
		snprintf(command_path, sizeof(command_path), "/%s", cmdString);

		const char *argv[] = {command_path,NULL};
		char *const env[] = {info->path, NULL};
	
		execve(command_path,(char *const *) argv, (char *const *)env);

		perror("execve");
		exit(EXIT_FAILURE);
	}
	
	else
		wait(NULL);
}

