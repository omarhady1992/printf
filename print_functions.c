#include "main.h"

/**
 * print_c- print chars
 *
 * @list_args:  pointer
 * @param: parameters struct
 *
 * Return: number chars printed
 */
int print_c(va_list list_args, params_t *param)
{
	char empty_string = ' ';
	unsigned int padding = 1, count = 0, cha = va_arg(list_args, int);

	if (param->minus_flag)
		count += _putchar(cha);

	while (padding++ < param->width)
		count += _putchar(empty_string);

	if (!param->minus_flag)
		count += _putchar(cha);

	return (count);
}

/**
 * print_i- print integer
 * @ap: pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_i(va_list ap, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ap, long);
	else if (params->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(_itoa(l, 10, 0, params), params));
}

/**
 * print_s-prints string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_s(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
	case 1:
		str = NULL_STRING;

		j = pad = _strlen(str);
		if (params->precision < pad)
			j = pad = params->precision;

		if (params->minus_flag)
		{
			if (params->precision != UINT_MAX)
				for (i = 0; i < pad; i++)
					sum += _putchar(*str++);
			else
				sum += _puts(str);
		}
		while (j++ < params->width)
			sum += _putchar(pad_char);
		if (!params->minus_flag)
		{
			if (params->precision != UINT_MAX)
				for (i = 0; i < pad; i++)
					sum += _putchar(*str++);
			else
				sum += _puts(str);
		}
		return (sum);
}

/**
 * print_percent-prints string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S-custom format specifier
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = _itoa(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
