#include "main.h"

/**
 * _printf - is a function that selects the correct function to print.
 * @format: format to check
 * Return: the length of the string.
 */

int _printf(const char * const format, ...)
{
	convert_match m[] = {
		{"%s", string_handler}, {"%c", char_handler},
		{"%%", percent_handler}, {"%d", dec_handler},
		{"%i", int_handler}, {"%b", binary_handler},
		{"%u", unsigned_handler}, {"%o", octal_handler},
		{"%x", hex_lower_handler}, {"%X", hex_upper_handler},
		{"%S", ex_string_handler}, {"%p", pointer_handler}
	};

	va_list args;
	int i = 0, j, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		j = 11;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len += m[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
