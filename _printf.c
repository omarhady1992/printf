#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 *
 * @format: composed of zero or more directives.
 * You need to handle the following conversion specifiers: c, s, %
 *
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{

	va_list args;
	int i = 0, j = 0, count = 0;
	char *str;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					j = va_arg(args, int);
					_putchar(j);
					count++;
					break;
				case 's':
					str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					while (str[j] != '\0')
					{
						_putchar(str[j]);
						j++;
						count++;
					}
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				case '\0':
					return (-1);
				default:
					_putchar('%');
					_putchar(format[i]);
					count += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
