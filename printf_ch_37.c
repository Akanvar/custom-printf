#include "main.h"
/**
 * print_char - prints a character
 * @fmt: character to be printed
 * Return: 0
 */
int print_char(va_list fmt)
{
	char ch;

	ch = va_arg(fmt, int);
	_putchar(ch);
	return (1);
}
/*===========================================*/
/**
 * print_percent - prints %
 * Return: 0
 */
int print_percent(void)
{
	_putchar('%');
	return (1);
}
