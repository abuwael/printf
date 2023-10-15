#include "main.h"

/**
 * manager - Receives the main string and all the necessary parameters to
 * print a formated string.
 *
 * @format: A string containing all the desired characters.
 * @ap: A list containing all the argumentents passed to the program.
 * @args_list: A list of all the posible functions.
 *
 * Return: A total count of the characters printed.
 */

int manager(const char *format, va_list ap, args_handle_t args_list[])
{
	int index, index2, re_val, chars;

	chars = 0;
	for (index = 0; format[index] != '\0'; index++)
	{
		if (format[index] == '%')
		{
			for (index2 = 0; args_list[index2].sym != NULL; index2++)
			{
				if (format[index + 1] == args_list[index2].sym[0])
				{
					re_val = args_list[index2].f(ap);
					if (re_val == -1)
						return (-1);
					chars += re_val;
					break;
				}
			}
			if (args_list[index2].sym == NULL && format[index + 1] != ' ')
			{
				if (format[index + 1] != '\0')
				{
					_write_char(format[index]);
					_write_char(format[index + 1]);
					chars = chars + 2;
				}
				else
					return (-1);
			}
			index = index + 1;
		}
		else
		{
			_write_char(format[index]);
			chars++;
		}
	}
	return (chars);
}
