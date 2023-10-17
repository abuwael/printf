#include "main.h"

/**
 * _printf - write output to stdout,
 * the standard output stream
 *
 * @format: is a character string.
 *
 * Return: the number of characters printed.
 */

int _printf(const char *format, ...)
{
	int len;
	va_list args;
	args_handle_t argsList[] = {
			{"c", print_char},
			{"s", print_string},
			{"%", print_percent},
			{"d", print_integers},
			{"i", print_integers},
			{"b", print_binary},
			{NULL, NULL}
		};

	if (format == NULL)
		return (-1);

	va_start(args, format);

	len = manager(format, args, argsList);

	va_end(args);

	return (len);
}
