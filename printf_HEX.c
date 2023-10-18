#include "main.h"
/**
 * print_HEX - prints an integer in hexadecimal form
 * with capital letters
 * @fmt: integer argument
 * @f: function pointer
 * Return: number of integers printed
 */
int print_HEX(va_list fmt, flag_t *f)
{
	unsigned int num;
	int i, j, count = 0, hexa[32];

	num = va_arg(fmt, unsigned int);

	if (f->hash == 1 && num != '0')
	{
		_putchar('0');
		_putchar('X');
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
			hexa[i] = num % 16;
			num /= 16;
			i++;
		}
	for (j = i - 1; j >= 0; j--)
	{
		if (hexa[j] > 9)
			hexa[j] = hexa[j] + 7;
		_putchar(hexa[j] + '0');
		count++;
	}
	return (count);
}
