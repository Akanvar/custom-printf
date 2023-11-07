#include <shell.h>
/**
 * check command - function to check if file of a command exists
 * @command - command to check
 */
void check_command(char *command)
{
	if (acces(command, F_OK) == 0)
		kelmprint("file found");
	else
		kelmprint("file does not exist");
}
