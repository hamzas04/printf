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
	char buffer[1024] = {0};
	char *buf_ptr = buffer;
	int remaining = sizeof(buffer);

	va_start(args, format);

	while (*format && remaining > 1)
	{
		if (*format == '%')
		{
			++format;
			switch (*format)
			{
				case 'c':
					*buf_ptr++ = va_arg(args, int);
					--remaining;
					++printed_chars;
					break;
				case 's':
					printed_chars += snprintf(buf_ptr, remaining, "%s", va_arg(args, char *));
					buf_ptr += printed_chars;
					remaining -= printed_chars;
					break;
				case 'd':
				case 'i':
					printed_chars += snprintf(buf_ptr, remaining, "%d", va_arg(args, int));
					buf_ptr += printed_chars;
					remaining -= printed_chars;
					break;
				case 'u':
					printed_chars += snprintf(buf_ptr, remaining, "%u", va_arg(args, unsigned int));
					buf_ptr += printed_chars;
					remaining -= printed_chars;
					break;
				case 'o':
					printed_chars += snprintf(buf_ptr, remaining, "%o", va_arg(args, unsigned int));
					buf_ptr += printed_chars;
					remaining -= printed_chars;
					break;
				case 'x':
					printed_chars += snprintf(buf_ptr, remaining, "%x", va_arg(args, unsigned int));
					buf_ptr += printed_chars;
					remaining -= printed_chars;
					break;
				case 'X':
					printed_chars += snprintf(buf_ptr, remaining, "%X", va_arg(args, unsigned int));
					buf_ptr += printed_chars;
					remaining -= printed_chars;
					break;
				case 'p':
					printed_chars += snprintf(buf_ptr, remaining, "%p", va_arg(args, void *));
					buf_ptr += printed_chars;
					remaining -= printed_chars;
					break;
				case 'b':
					{
						unsigned int value = va_arg(args, unsigned int);
						int bit_pos = 0;
						while (bit_pos < 32 && remaining > 1)
						{
							*buf_ptr++ = ((value >> (31 - bit_pos)) & 0x1) + '0';
							++bit_pos;
							--remaining;
							++printed_chars;
						}
					}
					break;
				case 'S':
					{
						char *str = va_arg(args, char *);
						while (*str && remaining > 1)
						{
							if (*str < ' ' || *str >= 127)
							{
								printed_chars += snprintf(buf_ptr, remaining, "\\x%02X", (unsigned char)*str);
								buf_ptr += printed_chars;
								remaining -= printed_chars;
							}
							else
							{
								*buf_ptr++ = *str;
								--remaining;
								++printed_chars;
							}
							++str;
						}
					}
					break;
				default:
					*buf_ptr++ = '%';
					*buf_ptr++ = *format;
					remaining -= 2;
					printed_chars += 2;
					break;
			}
		}
		else
		{
			*buf_ptr++ = *format;
			--remaining;
			++printed_chars;
		}
		++format;
	}

	va_end(args);

	fwrite(buffer, 1, buf_ptr - buffer, stdout);

	return printed_chars;
}
