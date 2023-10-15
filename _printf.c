#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: string
 *
 * Return: count
 */


int _printf(const char *format, ...)
{
	unsigned int i, count = 0;

	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
		}
		else if (format[i + 1] == 'c')
		{
			_putchar(va_arg(args, int));
			i++;
		}
		else if (format[i + 1] == 's')
		{
			_puts(va_arg(args, char*));
			i++;
		}
		else if (format[i + 1] == '%')
		{
			_putchar('%');
			i++;
		}
		count++;
	}
	va_end(args);
	return (count);
}
