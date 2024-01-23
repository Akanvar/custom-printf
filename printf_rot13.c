#include "main.h"
/**
 * print_rot13 - encoder rot13
 * @fmt: pointer to string
 * Return: number of characters printed
 */
int print_rot13(va_list fmt)
{
	char *str = va_arg(fmt, char *);
	int size = _strlen(str), i, j, count = 0;
	char *array = malloc(size + 1);
	char data1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char datarot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	if (array == NULL)
		return (0);
	if (str == NULL)
		return (0);
	_strcpy(array, str);
	for (i = 0; array[i] != '\0'; i++)
	{
		if ((array[i] >= 'A' && array[i] <= 'Z')
				|| (array[i] >= 'a' && array[i] <= 'z'))
		{
			for (j = 0; j < 52; j++)
			{
				if (array[i] == data1[j])
				{
					array[i] = datarot[j];
					_putchar(array[i]);
					count++;
					break;
				}
			}
		}
		else
		{	_putchar(array[i]);
			count++;
		}
	}
	free(array);
	return (count);
}
