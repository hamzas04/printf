#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - prints formatted output to stdout
 * @format: the format string
 *
 * Return: the number of characters printed
 *(excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int count = 0;

	while (*format != '\0') {
		if (*format == '%') {
			format++; // move past '%'

			// Handle conversion specifier
			switch (*format) {
				case 'c': {
					char c = (char) va_arg(args, int);
					putchar(c);
					count++;
					break;
				}
				case 's': {
					const char *s = va_arg(args, const char *);
					while (*s != '\0') {
						putchar(*s);
						s++;
						count++;
					}
					break;
				}
				case 'd':
				case 'i': {
					int num = va_arg(args, int);
					printf("%d", num);
					count += snprintf(NULL, 0, "%d", num);
					break;
				}
				case 'u': {
					unsigned int num = va_arg(args, unsigned int);
					printf("%u", num);
					count += snprintf(NULL, 0, "%u", num);
					break;
				}
				case 'o': {
					unsigned int num = va_arg(args, unsigned int);
					printf("%o", num);
					count += snprintf(NULL, 0, "%o", num);
					break;
				}
				case 'x':
				case 'X': {
					unsigned int num = va_arg(args, unsigned int);
					printf(*format == 'x' ? "%x" : "%X", num);
					count += snprintf(NULL, 0, "%x", num);
					break;
				}
				case 'p': {
					void *ptr = va_arg(args, void *);
					printf("%p", ptr);
					count += snprintf(NULL, 0, "%p", ptr);
					break;
				}
				case '%': {
					putchar('%');
					count++;
					break;
				}
				default: // unsupported conversion specifier
					putchar('%');
					putchar(*format);
					count += 2;
					break;
			}
		} else {
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);

	return count;
}
