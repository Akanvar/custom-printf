#include "main.h"
/**
 * print_hex_2 - prints an integer in hexadecimal form
 * @n: integer argument
 * Return: number of integers printed
 */
int print_hex_2(unsigned long int n)
{
	int i, j, count = 0, hex[32];

	if (n == 0)
	{
		_putchar(n);
		return (1);
	}
	i = 0;
	while
		(n > 0) {
			hex[i] = n % 16;
			n /= 16;
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
