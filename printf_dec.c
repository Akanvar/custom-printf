#include "main.h"
/**
 * print_d - prints integer given to %d
 * @fmt: integer argument
 * @f: function pointer
 * Return: number integers printed
 */
int print_d(va_list fmt, flag_t *f)
{
	int num, n, placeVal = 1, count = 0, val;

	n = va_arg(fmt, int);

	if (f->space == 1 && f->plus == 0 && n >= 0)
		count += _putchar(' ');
	if (f->plus == 1 && n >= 0)
		count += _putchar('+');
	if (n < 0)
	{
		_putchar('-');
		n = -n;
		count++;
	}
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
