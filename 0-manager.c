#include "main.h"

/**
 * manager - Receives the main string and all the necessary parameters to
 * print a formated string.
 *
 * @format: A string containing all the desired characters.
 * @args: A list containing all the argumentents passed to the program.
 * @args_list: A list of all the posible functions.
 *
 * Return: A total count of the characters printed.
 */

int manager(const char *format, va_list args, args_handle_t args_list[])
{
	int i1, i2, re_val, chars;

	chars = 0;
	for (i1 = 0; format[i1] != '\0'; i1++)
	{
		if (format[i1] == '%')
		{
			for (i2 = 0; args_list[i2].sym != NULL; i2++)
			{
				if (format[i1 + 1] == args_list[i2].sym[0])
				{
					re_val = args_list[i2].f(args);
					if (re_val == -1)
						return (-1);
					chars += re_val;
					break;
				}
			}
			if (args_list[i2].sym == NULL && format[i1 + 1] != ' ')
			{
				if (format[i1 + 1] != '\0')
				{
					_write_char(format[i1]);
					_write_char(format[i1 + 1]);
					chars = chars + 2;
				}
				else
					return (-1);
			}
			i1 = i1 + 1;
		}
		else
		{
			_write_char(format[i1]);
			chars++;
		}
	}
	return (chars);
}
