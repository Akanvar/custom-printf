#include <stdio.h>
#include <string.h>

int main(void)
{
	char array[] = "my name is mercy agbasah";
	char delim[] = " ";
	char *result;

	result = strtok(array, delim);

	while (result != NULL)
	{
		 printf("%s\n", result);
		result = strtok(NULL, delim);
	}

	return (0);
}

/*char *strtok(char *str, const char *delim)
{*/

