#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
/**
 * struct format_t - Struct to store format specifiers and their associated
 * @specifier: the format specifier character
 * @function: a function pointer to the function that handles the specifier
 */
typedef struct format_t
{
	char specifier;
	int (*function)(char **, va_list);
} format_t;

/* Custom printf function */
int _printf(const char *format, ...);
void print_binary(unsigned int num);

#endif /* MAIN_H */
