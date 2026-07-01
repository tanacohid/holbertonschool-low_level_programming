#include "main.h"
#include <stdio.h>

/**
 * _strlen - compte le nombre de caractere donner
 * @s: est la suite de char
 * Return: a
 */
int _strlen(char *s)
{
	int a;

	a = 0;

	while (*s != '\0')
	{
		a++;
		s++;
	}
	return (a);
}

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
