#include "main.h"

/**
 * print_binary - prints the binary equivalent of a number
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	int x, num = 0;
	unsigned long int current;

	for (x = 63; x >= 0; x--)
	{
		current = n >> x;

		if (current & 1)
		{
			_putchar('1');
			num++;
		}
		else if (num)
			_putchar('0');
	}
	if (!num)
		_putchar('0');
}
