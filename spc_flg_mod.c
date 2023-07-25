#include "main.h"

/**
 * get_spec-chooses the right function
 * @s:the identifiers
 * Return: no. bytes
 */
int (*get_spec(char *s))(va_list ap, params_t *params)

{
	specifier_t specs[] = {
		{"c", print_c},
		{"d", print_i},
		{"i", print_i},
		{"s", print_s},
		{"%", print_percent},
		{"b", print_bin},
		{"o", print_oct},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_addr},
		{"S", print_S},
		{"r", print_reverse},
		{"R", print_rota13},
		{NULL, NULL}
	};
	int i = 0;

	while (specs[i].specifier)
	{
		if (*s == specs[i].specifier[0])
			return (specs[i].f);
		i++;
	}
	return (NULL);
}

/**
 * assign_print_f-finds the format function
 * @s: string of the format
 * @ap: argument pointer
 * @params: the parameters struct
 * Return: the number of bytes printed
 */

int assign_print_f(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_spec(s);

	switch (f)
	{
		case true:
			return (f(ap, params));
		default:
			return (0);
	}
}

/**
 * get_flag - fun with flags
 * @s: the string
 * @params: the parameters struct
 * Return: if flag was valid
 */

int get_flag(char *s, params_t *params)
{
	int i = 0;

	if (*s == '+')
		i = params->plus_flag = 1;
	else if (*s == ' ')
		i = params->space_flag = 1;
	else if (*s == '0')
		i = params->zero_flag = 1;
	else if (*s == '-')
		i = params->minus_flag = 1;
	else if (*s == '#')
		i = params->hashtag_flag = 1;

	return (i);
}

/**
 * get_mod-finds the moderator
 * @s: string for format
 * @params: parameter structure
 * Return: if modifier was valid
 */

int get_mod(char *s, params_t *params)
{
	int i = 0;

	if (*s == 'h')
		i = params->h_modifier = 1;
	else if (*s == 'l')
		i = params->l_modifier = 1;
	return (i);
}

/**
 * get_w-how wide are you?
 * @s: the format string
 * @params: the parameters struct
 * @ap: the argument pointer
 * Return: new pointer
 */

char *get_w(char *s, params_t *params, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}
