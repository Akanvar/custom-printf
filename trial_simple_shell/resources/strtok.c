#include <stdio.h>
#include <string.h>

int main(void)
{
	char array[] = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
	char delim[] = ":";
	char *result;

	result = strtok(array, delim);
	printf("%s\n", result);

/*	while (result != NULL)
	{
		 printf("%s\n", result);
		result = strtok(NULL, delim);
	} */

	return (0);
}

/*char *strtok(char *str, const char *delim)
{*/

