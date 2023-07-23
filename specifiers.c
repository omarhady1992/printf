#include "main.h"

/**
 * get_specifier-determines the printing function to be used
 * corresponding to the input identifier
 * @s: the format string
 * Return: number of bytes
 */

int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t speciifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (speciifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func-supporting function that returns the format function
 * @s: the identifier string
 * @ap: the argument ptr
 * @params: a struct of parameters
 * Return: Number of printed bytes
 */

int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_speciifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}


/**
 * get_flag-gets the special cases flags from a string
 * @s: input string
 * @params: struct prameters
 * Return: validity of the flag
 */

int get_flag(char *s, params_t *params)
{
	{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}


/**
 * get_modifier-a function that gets the modifier
 * @s: input modifier string
 * @params: parameterst struct
 * Return: validity of modifier
 */

int get_modifier(char *s, params_t *params)
{
	int i = 0;

	if (*s == 'h')
	{
		i = params->h_modifier = 1;
		break;
	} else if (*s == 'l')
	{
		i = params->l_modifier = 1;
		break;
	}
	return (i);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @params: parameters struct
 * @ap: the argument ptr
 *
 * Return: a ptr
 */

char *get_width(char *s, params_t *params, va_list ap)
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
