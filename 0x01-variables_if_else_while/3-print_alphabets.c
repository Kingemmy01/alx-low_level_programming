#include <stdio.h>

/**
* main - A program that prints the alphabet in lowercase,
* and then in uppercase
* Return: Always 0 (Success)
*/
int main(void)
{
	char lu;

	for (lu = 'a'; lu <= 'z'; lu++)
		putchar(lu);

	for (lu = 'A'; lu <= 'Z'; lu++)
		putchar(lu);

	putchar('\n');

	return (0);
}
