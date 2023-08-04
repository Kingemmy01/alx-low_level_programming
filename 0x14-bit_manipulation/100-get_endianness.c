#include "main.h"

/**
 * get_endianness - a function that checks the endianness
 * Return: 0 for big, 1 for little endian
 */
int get_endianness(void)
{
	unsigned int x = 1;
	char *s = (char *) &x;

	return (*s);
}
