#include "main.h"
/**
 * string_handler - print a string.
 * @val: argumen t.
 * Return: the length of the string.
 */

int string_handler(va_list val)
{
	char *s;
	int i, len;

	s = va_arg(val, char *);
	if (s == NULL)
	{
		s = "(null)";
		len = _strlen(s);
		for (i = 0; i < len; i++)
			_putchar(s[i]);
		return (len);
	}
	else
	{
		len = _strlen(s);
		for (i = 0; i < len; i++)
			_putchar(s[i]);
		return (len);
	}
}



/**
 * char_handler - prints a char.
 * @val: arguments.
 * Return: 1.
 */

int char_handler(va_list val)
{
	char s;

	s = va_arg(val, int);
	_putchar(s);
	return (1);
}

/**
 * percent_handler - prints %.
 * Return: 1.
 */

int percent_handler(void)
{
        _putchar(37);
        return (1);
}

