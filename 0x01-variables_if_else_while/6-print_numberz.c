#include <stdio.h>
/**
 * main - A program that prints single digits in base 10
 * Return: Alaways 0 (Success)
 */
int main(void)
{
	int num;

	for (num = 0; num < 10; num++)
		putchar((num % 10) + '0');

	putchar('\n');

	return (0);
}
