#include "main.h"

/**
 * _putchar - writes the char c to standard output
 * @c: The character to print
 * Return: char with write function
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
