#include "main.h"

/**
 * _puts - print to std out and add newline
 * @str: to be printed
 *
 * Return: nothing
 */
int _puts(char *str)
{
	char *p = str;

	while (*str)
		_putchar(*str++);
	return (str - p);
}
