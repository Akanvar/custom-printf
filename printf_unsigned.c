#include "main.h"
/**
 * print_u - prints an unsigned integer
 * @fmt: integer argument
 * @f: function pointer
 * Return: number integers printed
 */
int print_u(va_list fmt, flag_t *f)
{
	unsigned int n, num;
	int placeVal = 1, count = 0, val;

	n = va_arg(fmt, int);

	if (f->space == 1 && f->plus == 0)
		count += _putchar(' ');
	if (f->plus == 1)
		count += _putchar('+');
	num = n;
	while
		(num / 10 != 0) {
			placeVal = placeVal * 10;
			num /= 10;
		}
	num = n;
	while
		(placeVal > 0) {
			val = num / placeVal;
			_putchar(val + '0');
			num = num - (val * placeVal);
			placeVal /= 10;
			count++;
		}
	return (count);
}
