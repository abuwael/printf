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
	va_list ap;
	args_handle_t argsList[] = {
			{"c", print_char},
			{"s", print_string},
			{"%", print_percent},
			{NULL, NULL}
		};

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	len = manager(format, ap, argsList);

	va_end(ap);

	return (len);
}
