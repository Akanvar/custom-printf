#include "shell.h"
/**
 * exeCMD - function to execote command
 * @cmdString: command to be executed
 */
extern char **environ;

void exeCMD(const char *cmdString)
{
	/*pid_t pid = fork();*/

	printf("%s\n", *environ);
}

	/*if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) 
	{

		char command_path[256];
		snprintf(command_path, sizeof(command_path), "/%s", cmdString);

		char *args[] = {command_path, NULL};
		execve(command_path, args, environ);

		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}*/

