#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* _puts.c and _putchar.c  modules */
int _putchar(int c);
int _puts(char *str);

int _printf(const char *format, ...);

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: + flg toggle
 * @space_flag: space flg toggle
 * @hashtag_flag: # flag toggle
 * @zero_flag: 0 flg toggle
 * @minus_flag: - flag toggle
 * @width: width of printing
 * @precision: precision 
 *
 * @h_modifier: h_modifier toggle
 * @l_modifier: l_modifier toggle
 *
 */

typedef struct parameters
{
	unsigned int unsign		: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - specifier token
 *
 * @specifier:  token
 * @f: function related to specifier
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

#endif
