#include "main.h"
/**
 * set_flag - turns on flag if printf finds a flag
 * modifier in the format string
 * @ch: character that holds the flag specifier
 * @f: pointer to struct flag
 * Return: 1 if flag is turn on, else 0
 */
int set_flag(char ch, flag_t *f)
{
	int i = 0;

	if (ch == '+')
	{
		f->plus = 1;
		i = 1;
	}
	else if (ch == ' ')
	{
		f->space = 1;
		i = 1;
	}
	else if (ch == '#')
	{
		f->hash = 1;
		i = 1;
	}
	else if (ch == '0')
	{
		f->zero = 1;
		i = 1;
	}
	else if (ch == '-')
	{
		f->minus = 1;
		i = 1;
	}
	else
		i = 0;
	return (i);
}
