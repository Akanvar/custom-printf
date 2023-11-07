#include <stdio.h>
#include <string.h>

void _strtok(const char *str, char delim)
{
	int len = strlen(str);
	char array[len + 1];
	int i, j;

	for (i = 0; i < len; i++)
	{
		j = 0;
		if (str[i] == delim || str[i] == '\0')
		{
			array[j] = '\0';
			if (j > 0)
			{
				printf("%s\n",array);
				j = 0;
			}
			array[j++] = str[i];
		}
	}
}

int main()
{
	const char str[] = "my name is mercy agbasah";
	char delim[] = " ";
	char *st = _strtok(str, delim);
	printf("%s\n", st);
	return 0;

}

