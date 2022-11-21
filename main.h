#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct format
{
	char *id;
	int (*f)();
} convert_match;

int _printf(const char *format, ...);
int _putchar(char c);
int char_handler(va_list val);
int string_handler(va_list val);
int percent_handler(void);
int _strlen(char *s);
int dec_handler(va_list args);
int int_handler(va_list args);
int binary_handler(va_list val);
int unsigned_handler(va_list args);
int octal_handler(va_list args);
int hex_lower_handler(va_list args);
int hex_upper_handler(va_list args);
int ex_string_handler(va_list val);

#endif
