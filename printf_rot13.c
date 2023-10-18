#include "main.h"

/**
 * print_rot13 - encoder rot13
 * @fmt: pointer to string
 * Return: number of characters printed
 */

int print_rot13(va_list fmt)
{
	char *str;
	int i, j, count = 0;
	char data1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char datarot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(fmt, char *);

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (str[i] == data1[j])
			{
				str[i] = datarot[j];
				_putchar(str[i]);
				count++;
				break;
			}
		}
	}
	return (count);
}
