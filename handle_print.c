#include "main.h"
/**
 * handle_print - selects the right printing function
 * depending on the conversion specifier passed to _printf
 * @ch: character that holds the conversion specifier
 * z[] to find a match between the specifier passed to _printf
 * and the first element of the struct, and then the approriate
 * printing function
 * Return: a pointer to a function
 */
int (*handle_print(char ch))(va_list, flag_t *)
{
	specifiers z[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_percent}, {'d', print_d},
		{'i', print_i}, {'b', print_bin}, {'u', print_u}, {'o', print_oct},
		{'x', print_hex}, {'X', print_HEX}, {'S', print_STR}, {'p', print_ad},
		{'r', print_rev}, {'R', print_rot13}
		};

	int index = 13;

	while
		(index >= 0) {
			if (z[index].spec == ch)
				return (z[index].pt);
			index--;
			}
	return (NULL);
}
