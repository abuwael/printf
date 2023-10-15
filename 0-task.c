#include "main.h"

/**
 * _write_char - writes the character c to stdout.
 *
 * @c: The character to print
 *
 * Return: On success 1 else -1.
 */

int _write_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - Prints character
 *
 * @list: list of arguments
 *
 * Return: Will return the amount of characters printed.
 */

int print_char(va_list list)
{
	_write_char(va_arg(list, int));
	return (1);
}

/**
 * print_string - Prints a string
 * @list: list of arguments
 * Return: Will return the amount of characters printed.
 */

int print_string(va_list list)
{
	int i;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_write_char(str[i]);
	return (i);
}

/**
 * print_percent - Prints a percent symbol
 *
 * @list: list of arguments
 *
 * Return: Will return the amount of characters printed.
 */

int print_percent(__attribute__((unused))va_list list)
{
	_write_char('%');
	return (1);
}
