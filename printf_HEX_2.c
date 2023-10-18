#include "main.h"
/**
 * print_HEX_2 - prints an integer in hexadecimal form
 * with capital letters
 * @n: integer argument
 * Return: number of integers printed
 */
int print_HEX_2(unsigned int n)
{
	int i, j, count = 0, hexa[32];

	if (n == 0)
	{
		_putchar(n);
		return (1);
	}
	i = 0;
	while
		(n > 0) {
			hexa[i] = n % 16;
			n /= 16;
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
