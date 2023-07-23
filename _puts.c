#include "main.h"

/**
 * _puts - prints a string on the screen followed by a new line
 * @str: input string to be displayed
 *
 * Return: Void
 */

int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}
