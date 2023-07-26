#include "main.h"

/**
 * _printf - prints to std out
 * @format: of the input to be printed
 * Return: how many chars printed
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list list_args;
	char *ptr, *start;
	params_t param = PARAMS_INIT;

	va_start(list_args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (ptr = (char *)format; *ptr; ptr++)
	{
		initiate_parameters(&param, list_args);
		if (*ptr != '%')
		{
			count += _putchar(*ptr);
			continue;
		}
		start = ptr;
		ptr++;
		while (get_flag(ptr, &param))
		{
			ptr++;
		}
		ptr = get_w(ptr, &param, list_args);

		ptr = get_prec(ptr, &param, list_args);

		if (get_mod(ptr, &param))
			ptr++;

		if (!get_spec(ptr))
			count += print_from_to(start, ptr,
					param.l_modifier || param.h_modifier ? ptr - 1 : 0);
		else
			count += assign_print_f(ptr, list_args, &param);
	}

	_putchar(BUF_FLUSH);
	va_end(list_args);
	return (count);
}
