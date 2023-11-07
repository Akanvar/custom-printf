#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	pid_t child;
	int i;
	char *arg[] = {"ls", "-l", "/tmp", NULL};
	
	for (i = 0; i < 6; i++)
	{
		child = fork();
		if (child == -1)
		{
			perror("error");
			exit(EXIT_FAILURE);
		}
	}
	if (child == 0)
	{
		 execve("/usr/bin/ls", arg, NULL);
		 perror("error");
		 exit(EXIT_FAILURE);

	}
	else
		wait(NULL);
	return 0;
}
