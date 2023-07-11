#include "main.h"
#include <stdlib.h>

/**
* str_concat - function that concatenates two strings.
* @s1: input one to concat
* @s2: input two to concat
* Return: concat of s1 and s2
*/
char *str_concat(char *s1, char *s2)
{
	char *s3;
	int i, ci;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	i = ci = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[ci] != '\0')
		ci++;
	s3 = malloc(sizeof(char) * (i + ci + 1));

	if (s3 == NULL)
		return (NULL);
	i = ci = 0;
	while (s1[i] != '\0')
	{
	s3[i] = s1[i];
		i++;
	}

	while (s2[ci] != '\0')
	{
	s3[i] = s2[ci];
		i++, ci++;
	}
	s3[i] = '\0';
	return (s3);

}
