#include "main.h"
/**
 * _printf - custom printf function
 * @format: specifier to look for
 * Return: integer
 */
int _printf(const char *format, ...)
{
	va_list fmt;
	int (*ptrF)(va_list, flag_t *);
	char buffer[BUFF_SIZE];
	int len = 0, bufferIndex = 0;
	flag_t flags = {0, 0, 0, 0, 0};

	if (format == NULL)
		return (-1);
	va_start(fmt, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			buffer[bufferIndex++] = *format;
			if (bufferIndex == BUFF_SIZE)
				print_buffer(buffer, &bufferIndex);
			len++;
		}
		else
		{
			print_buffer(buffer, &bufferIndex);
			format++;
			while
				(set_flag(*format, &flags)) {
					format++;
				}
			ptrF = handle_print(*format);
			if (ptrF != NULL)
				len += ptrF(fmt, &flags);
			else
				return (-1);
		}
		format++;
	}
	print_buffer(buffer, &bufferIndex);
	va_end(fmt);
	return (len);
}
