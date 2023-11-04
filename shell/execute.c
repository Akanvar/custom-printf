#include "shell.h"
/**
 * exeCMD - function to execote command
 * @cmdString: command to be executed
 */


void exeCMD(const char *cmdString)
{
	int i = 0, j = 0;
	const char *pathStr;
	pid_t pid = fork();
	const info_t *info;


	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) 
	{
		info->path = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
		for (i = 5; info->path[i] != '\0'; i++)
			pathStr[j++] = info->path[i];



		char command_path[256] = find_path(NULL, pathStr, cmdString);
		snprintf(command_path, sizeof(command_path), "/%s", cmdString);

		const char *args[] = {command_path, NULL};
		execve(command_path, args, info->path);

		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}

