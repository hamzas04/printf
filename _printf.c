#include <stdio.h>
#include <stdarg.h>

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

	return printed_chars;
}
