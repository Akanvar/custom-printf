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

	str = va_arg(fmt, char *);
	if (str == NULL)
		return (0);
	str_len = _strlen(str);
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	return (str_len);
}
