#include "main.h"

/**
 * rev_string - reverses a string
 * @s: pointer to the string
 */
void rev_string(char *s)
{
	int debut;
	int fin;
	char temp;

	debut = 0;
	fin = _strlen(s) - 1;

	while (debut < fin)
	{
		temp = s[debut];
		s[debut] = s[fin];
		s[fin] = temp;

		debut++;
		fin--;
	}
}