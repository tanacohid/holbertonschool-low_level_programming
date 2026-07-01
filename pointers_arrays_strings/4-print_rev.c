#include "main.h"

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
* print_rev - prints a string in reverse
* @s: pointer to the string
*/
void print_rev(char *s)
{
	int i;

	i = _strlen(s) - 1;

	while (i >= 0)
	{
		_putchar(s[i]);
		i--;
	}

	_putchar('\n');
}
