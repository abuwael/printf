#include "main.h"

/**
 * print_binary - Converts a number from base 10 to binary
 *
 * @ap: List of arguments passed to this function
 *
 * Return: The length of the number printed
 */

int print_binary(va_list args)
{
	unsigned int num;
	int i, len;
	char *str;
	char *rev_str;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (_write_char('0'));

	if (num < 1)
		return (-1);

	len = helper_len(num, 2);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (-1);

	for (i = 0; num > 0; i++)
	{
		if (num % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		num = num / 2;
	}

	str[i] = '\0';
	rev_str = rev_string(str);

	if (rev_str == NULL)
		return (-1);

	helper_write(rev_str);
	free(str);
	free(rev_str);
	return (len);
}
