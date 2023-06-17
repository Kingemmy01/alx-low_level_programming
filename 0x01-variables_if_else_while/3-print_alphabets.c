#include <stdio.h>
/**
* main - A program that prints the alphabet in lowercase, and then in uppercase
* return: Always 0 (Success)
*/

int main(void)
{
	int c = 97;
	int d = 65;

	while (c <= 122);
	{
		putchar(c);
		c++;
	}
	while (d <= 90)
	{
		putchar(d);
		d++;
	}
	putchar('\n');
	return (0);
}
