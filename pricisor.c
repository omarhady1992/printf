#include "main.h"

/**
 * get_prec-extracts precisiors
 * @p: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 * Return: new pointer
 */

char *get_prec(char *ptr, params_t *params, va_list ap)
{
	int d = 0;

	if (*ptr != '.')
		return (ptr);
	ptr++;
	switch (*ptr)
	{
		case '*':
			d = va_arg(ap, int);
			ptr++;
		default:
			while (_isdigit(*ptr))
			d = d * 10 + (*ptr++ - '0');
	}
	params->precision = d;
	return (ptr);
}
