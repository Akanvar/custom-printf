#include "shell.h"
/**
 * **_strtok - tokenizes a string.Ignores repeat delimiters
 * @string: the input string
 * @delim: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **_strtok(char *string, char *delim)
{
	int i, j, k, m, wordcount = 0;
	char **s;

	if (string == NULL || string[0] == '\0')
		return (NULL);
	if (delim == NULL)
		delim = " ";
	for (i = 0; string[i] != '\0'; i++)
		if (!check_delim(string[i], delim) && (check_delim(string[i + 1], delim) || !string[i + 1]))
			wordcount++;

	if (wordcount == 0)
		return (NULL);
	s = malloc((1 + wordcount) * sizeof(char *));
	if (s == NULL)
		return (NULL);
	for (i = 0, j = 0; j < wordcount; j++)
	{
		while (check_delim(string[i], delim))
			i++;
		k = 0;
		while (!check_delim(string[i + k], delim) && string[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (s[j] == NULL)
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = string[i++];
		s[j][m] = '\0';
	}
	s[j] = NULL;
	//free(s);
	return (s);
}

/**
 * check_delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 0 if true, -1 if false
 */
int check_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/*int main()
{
    char *st = "exit";
    char *d = " ";
    char **s = _strtok(st, " ");

    if (s != NULL) {
        int i = 0;
        while (s[i] != NULL) {
            printf("Token %d: %s\n", i + 1, s[i]);
            i++;
        }
	if (strcmp(s[0], "exit") == 0) {
		printf("It's not me!");
	}
	else
		printf("Its  me");	

       //  Free memory allocated for the tokens
        for (i = 0; s[i] != NULL; i++) {
            free(s[i]);
        }
        free(s);
    } else {
        printf("Tokenization failed.\n");
    }

    return 0;
}*/
