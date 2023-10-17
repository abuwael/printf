#include "main.h"


/**
 * print_unsgined_number - Prints an unsigned number
 *
 * @n: unsigned integer to be printed
 *
 * Return: The amount of numbers printed
 */

int print_unsgined_number(unsigned int n)
{
	int div;
	int len;
	unsigned int num;

	div = 1;
	len = 0;

	num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _write_char('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}

/**
 * unsigned_integer - Prints Unsigned integers
 *
 *  @ap: List of all the arguments passed to the program
 *
 *  Return: a count of the numbers
 */

int unsigned_integer(va_list ap)
{
	unsigned int num;

	num = va_arg(ap, unsigned int);

	if (num == 0)
		return (print_unsgined_number(num));

	if (num < 1)
		return (-1);
	return (print_unsgined_number(num));
}


/**
 * print_octal - Prints the numeric representation of a number in octal base
 *
 *  @ap: List of all the arguments passed to the program
 *
 *  Return: Number of symbols printed to stdout
 */

int print_octal(va_list ap)
{
	unsigned int num;
	int len;
	char *octal_rep;
	char *rev_str;

	num = va_arg(ap, unsigned int);

	if (num == 0)
		return (_write_char('0'));
	if (num < 1)
		return (-1);
	len = helper_len(num, 8);

	octal_rep = malloc(sizeof(char) * len + 1);

	if (octal_rep == NULL)
		return (-1);

	for (len = 0; num > 0; len++)
	{
		octal_rep[len] = (num % 8) + 48;
		num = num / 8;

	}
	octal_rep[len] = '\0';

	rev_str = rev_string(octal_rep);

	if (rev_str == NULL)
		return (-1);

	helper_write(rev_str);
	free(octal_rep);
	free(rev_str);
	return (len);
}
