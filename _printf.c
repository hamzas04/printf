#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - prints formatted output to stdout
 * @format: the format string
 *
 * Return: the number of characters printed
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
                    print_binary(va_arg(args, unsigned int));
                    printed_chars += sizeof(unsigned int) * 8;
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
