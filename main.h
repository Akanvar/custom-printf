#ifndef MAIN_H
#define MAIN_H

#define BUFF_SIZE 1024

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct fmt_specifiers
{
	char spec;
	int (*pt)();
} specifiers;

typedef struct flag_type
{
	int plus;
	int space;
	int hash;
	int zero;
	int minus;
} flag_t;

int set_flag(char ch, flag_t *f);
int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list fmt);
int print_str(va_list fmt);
int print_percent(void);
int _strlen(char *str);
int print_d(va_list fmt, flag_t *f);
int print_i(va_list fmt, flag_t *f);
int print_bin(va_list fmt);
int print_u(va_list fmt, flag_t *f);
int print_oct(va_list fmt, flag_t *f);
int print_hex(va_list fmt, flag_t *f);
int print_HEX(va_list fmt, flag_t *f);
int print_HEX_2(unsigned int n);
int print_STR(va_list fmt);
int print_hex_2(unsigned long int n);
int print_ad(va_list fmt);
int print_rev(va_list fmt);
int print_rot13(va_list fmt);
void print_buffer(char buffer[], int *bufferIndex);
int (*handle_print(char ch))(va_list, flag_t *);

#endif
