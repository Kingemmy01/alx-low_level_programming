#include "main.h"

/**
 * binary_to_uint - function that converts a binary number to an unsigned int
 * @b: string pointing to the binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int x;
	unsigned int dec_val = 0;

	if (!b)
		return (0);

	for (x = 0; b[x]; x++)
	{
		if (b[x] < '0' || b[x] > '1')
			return (0);
		dec_val = 2 * dec_val + (b[x] - '0');
	}

	return (dec_val);
}
