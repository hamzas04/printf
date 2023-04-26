#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - prints formatted output to stdout
 * @format: the format string
 *
 * Return: the number of characters printed
 *
 */
 
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			++format;
			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));
					++printed_chars;
					break;
				case 's':
					printed_chars += printf("%s", va_arg(args, char *));
					break;
				case 'd':
				case 'i':
					printed_chars += printf("%d", va_arg(args, int));
					break;
				case 'b':
					{
						unsigned int num = va_arg(args, unsigned int);
						int binary[32];
						int i = 0;

						while (num > 0) {
							binary[i] = num % 2;
							num = num / 2;
							i++;
						}

						for (int j = i - 1; j >= 0; j--) {
							printf("%d", binary[j]);
						}
						printed_chars += i;
						break;
					}
				case '%':
					putchar('%');
					++printed_chars;
					break;
				default:
					putchar('%');
					putchar(*format);
					printed_chars += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			++printed_chars;
		}
		++format;
	}

	va_end(args);

	return (printed_chars);
}
