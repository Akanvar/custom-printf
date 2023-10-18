#include "main.h"
/**
 * print_oct - prints an integer in octal form
 * @fmt: integer argument
 * @f: function pointer
 * Return: number of integers printed
 */
int print_oct(va_list fmt, flag_t *f)
{
	unsigned int num;
	int i, j, count = 0, oct[32];

	num = va_arg(fmt, unsigned int);

	if (f->hash == 1 && num != '0')
	{
		_putchar('0');
		count++;
	}
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	i = 0;
	while
		(num > 0) {
			oct[i] = num % 8;
			num /= 8;
			i++;
		}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(oct[j] + '0');
		count++;
	}
	return (count);
}
