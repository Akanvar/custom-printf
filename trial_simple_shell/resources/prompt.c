#include <stdio.h>
int main()
{
	size_t n;
	char *buff;

	printf("$");
	getline(&buff, &n, stdin);
	printf("%s", buff);


	return 0;
}

