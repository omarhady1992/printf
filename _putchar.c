# include "main.h"

/**
 * _putchar - print char to std out
 * @s: char to print
 *
 * Return: 1 if sucess
 * -1 if error
 * error num is set
 */
int _putchar(int s)
{
	static int i;
	static char buffer[OUTPUT_BUF_SIZE];

	if (s == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (s != BUF_FLUSH)
		buffer[i++] = s;
	return (1);
}
