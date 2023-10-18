#include "main.h"
/**
 * print_STR - prints an exclusive string
 * @fmt: string argument
 * Return: number of characters printed
 */
int print_STR(va_list fmt)
{
	char *str;
	int len = 0, num;

	str = va_arg(fmt, char *);
	if (str == NULL)
		return (0);
	while
		(*str != '\0') {
			if (*str < 32 || *str >= 127)
			{
				_putchar('\\');
				_putchar('x');
				len += 2;
				num = *str;
				if (num < 16)
				{
					_putchar('0');
					len += 1;
				}
				len += print_HEX_2(num);
			}
			else
			{
				_putchar(*str);
				len++;
			}
			str++;
		}
	return (len);
}
