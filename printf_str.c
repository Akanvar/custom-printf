#include "main.h"
/**
 * print_str - prints a string
 * @fmt: string to be printed
 * Return: number of characters printed, else 0 if error
 */

int print_str(va_list fmt)
{
	char *str;
	int str_len;
/*	char *strArray; */

	str = va_arg(fmt, char *);
	if (str == NULL)
		return (-1);
	str_len = _strlen(str);

	/*strArray = (char *)malloc(str_len + 1);
	if (strArray == NULL)
		return (0);
	_strcpy(strArray, str); */

	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	/*free(str); */
	return (str_len);
}
