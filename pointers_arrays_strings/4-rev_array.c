#include "main.h"

/**
 * rev_string - reverses a string
 * @s: pointer to the string
 */
void rev_string(char *s)
{
	int i;

	i = _strlen(s);

	for ((i = _strlen(s)); (s[i]) >= '0'; (s[i])--)
	{
		_putchar (s[i]);
	}
}
