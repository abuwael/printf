#include "main.h"

/**
 * _puts - print string
 *
 * @c: string
 * Return: number of byte
 */

int _puts(char *c)
{
	int i = 0;

	if (c)
	{
		for (i = 0; c[i] != '\0'; i++)
		{
			_putchar(c[i]);
		}
	}
	return (i);
}
