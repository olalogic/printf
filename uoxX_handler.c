#include "main.h"

/**
 * unsigned_handler - prints unsigned integer
 * @args: argument
 * Return: number of characters printed
 */

int unsigned_handler(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int num, last = n % 10, digit, exp = 1;
	int  i = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	_putchar(last + '0');

	return (i);
}


/**
 * octal_handler - prints octal number.
 * @val: arguments.
 * Return: counter.
 */

int octal_handler(va_list val)
{
	int i;
	int *arr;
	int c = 0;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int temp = num;

	while (num / 8 != 0)
	{
		num /= 8;
		c++;
	}
	c++;
	arr = malloc(c * sizeof(int));

	for (i = 0; i < c; i++)
	{
		arr[i] = temp % 8;
		temp /= 8;
	}
	for (i = c - 1; i >= 0; i--)
	{
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (c);
}


/**
 * hex_lower_handler - prints lower case hexadecimal number
 * @val: arguments.
 * Return: counter.
 */

int hex_lower_handler(va_list val)
{
	int i;
	int *arr;
	int c = 0;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		c++;
	}
	c++;
	arr = malloc(c * sizeof(int));

	for (i = 0; i < c; i++)
	{
		arr[i] = temp % 16;
		temp /= 16;
	}
	for (i = c - 1; i >= 0; i--)
	{
		if (arr[i] > 9)
			arr[i] = arr[i] + 39;
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (c);
}


/**
 * hex_upper_handler - prints upper hexadecimal number
 * @val: arguments.
 * Return: counter.
 */

int hex_upper_handler(va_list val)
{
	int i;
	int *arr;
	int c = 0;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		c++;
	}
	c++;
	arr = malloc(c * sizeof(int));

	for (i = 0; i < c; i++)
	{
		arr[i] = temp % 16;
		temp /= 16;
	}
	for (i = c - 1; i >= 0; i--)
	{
		if (arr[i] > 9)
			arr[i] = arr[i] + 7;
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (c);
}
