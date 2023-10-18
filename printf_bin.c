#include "main.h"
/**
 * print_bin - prints an integer in binary form
 * @fmt: integer argument
 * Return: number of integers printed
 */
int print_bin(va_list fmt)
{
	unsigned int num;
	int i, j, count = 0, bin[32];

	num = va_arg(fmt, unsigned int);

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	i = 0;
	while
		(num > 0) {
			bin[i] = num % 2;
			num /= 2;
			i++;
		}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(bin[j] + '0');
		count++;
	}
	return (count);
}
