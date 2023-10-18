#include "main.h"
/**
 * print_hex - prints an integer in hexadecimal form
 * @fmt: integer argument
 * @f: function pointer
 * Return: number of integers printed
 */
int print_hex(va_list fmt, flag_t *f)
{
	unsigned int num;
	int i, j, count = 0, hex[32];

	num = va_arg(fmt, unsigned int);

	if (f->hash == 1 && num != '0')
	{
		_putchar('0');
		_putchar('x');
		count += 2;
	}
	else if (num == 0)
	{
		_putchar(num);
		return (1);
	}
	i = 0;
	while
		(num > 0) {
			hex[i] = num % 16;
			num /= 16;
			i++;
		}
	for (j = i - 1; j >= 0; j--)
	{
		if (hex[j] > 9)
			hex[j] = hex[j] + 39;
		_putchar(hex[j] + '0');
		count++;
	}
	return (count);
}
