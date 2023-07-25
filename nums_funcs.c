#include "main.h"

/**
 * _itoa- function that imitates itoa for numbers
 * @num: integer input
 * @base: the base of number (binary, dec, hex)
 * @flag: argument flags
 * @params: is the parameter struct
 */

char *_itoa(long int n, int base, int flag, param_t *params)
{
     static char *array;
     static char buffer[50];
     char *p;
     char sign = 0;
     unsigned long int n = num;
     (void)params;

     if (!(flag & CONVERT_UNSIGNED) && num < 0)
     {
	     n = -num;
	     sign = '-';
     }
     if (flag & CONVERT_LOWERCASE)
	     array = "0123456789abcdef";
     else
	     array = "0123456789ABCDEF";
     p = &buffer[49];
     *p = '\0';
     while (n != 0)
     {
	     *--p = array[n % base];
	     n /= base;
     }
     
     switch (sign)
     {
	     case true:
		     *--p = sign;
     }
     return (p);

}


/**
 * print_addr-function that prints the address of the input
 * @ap: argument pointer
 * @params: parameter struct
 * Return: number of bytes printed
 */

int print_addr(va_list ap, params_t *params)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = _itoa(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}


/**
 * print_unsigned-prints unsigned integer numbers
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_unsigned(va_list ap, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(_itoa(l, 10, CONVERT_UNSIGNED, params), params));
}

