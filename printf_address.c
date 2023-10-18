#include "main.h"
/**
 * print_ad - print the address held by a pointer
 * @fmt: address to print
 * Return: number of characters printed
 */
int print_ad(va_list fmt)
{
	void *ptr;
	unsigned long int val;
	int num;

	ptr = va_arg(fmt, void *);
	if (ptr == NULL)
		return (0);
	val = (unsigned long int)ptr;
	_putchar('0');
	_putchar('x');
	num = print_hex_2(val);

	return (num + 2);
}
