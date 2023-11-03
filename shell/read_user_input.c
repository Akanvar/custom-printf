#include "shell.h"
/**
 * userCMD - reads user input
 * @cmdString: user's command
 * @size: length of the command
 */

void userCMD(char *cmdString, size_t size)
{
	if (fgets(cmdString, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			myPrintf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			myPrintf("Command not recognized.\n");
			exit(EXIT_FAILURE);
		}
	}
	cmdString[strcspn(cmdString, "\n")] = '\0';
}
