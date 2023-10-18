#include "main.h"
/**
 * print_rev - prints string in reverse, followed by newline
 * @fmt: string
 * Return: number of characters printed
 */
int print_rev(va_list fmt)
{
	char *s;
	int i, count = 0;

	s = va_arg(fmt, char *);
	if (s == NULL)
		return (0);

	while
		(*s != '\0') {
			count++;
			s++;
		}
	s--;
	for (i = count; i > 0; i--)
	{
		_putchar(*s);
		s--;
	}
	return (count);
}
