#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

/**
* struct args_handle - defines a structure
* for symbols and functions
*
* @sym: The operator
* @f: The function associated
*/

struct args_handle
{
	char *sym;
	int (*f)(va_list);
};
typedef struct args_handle args_handle_t;

int manager(const char *format, va_list ap, args_handle_t args_list[]);
int _write_char(char);
int _putchar(char c);
int print_char(va_list arg);
int print_string(va_list arg);
int print_percent(va_list);
int print_integers(va_list args);
int print_binary(va_list);

/*Helper Functions*/
unsigned int helper_len(unsigned int, int);
char *rev_string(char *);
int helper_write(char *str);
int print_unsgined_number(unsigned int);
int flager(const char *format, int *i);

int _printf(const char *format, ...);

#endif
