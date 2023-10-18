#include "main.h"
/**
 * _strlen - returns the length of a string
 * @str: string
 * Return: string length
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}
