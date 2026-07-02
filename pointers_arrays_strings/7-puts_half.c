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
* puts_half - prints every other character of a string
* @str: pointer to the string
*/
void puts_half(char *str)
{
	int i;
	int t;

	i = (_strlen(str) + 1) / 2;
	t = _strlen(str);

	for (i = (_strlen(str) + 1) / 2; str[i] != str[t]; i++)
		_putchar(str[i]);
	_putchar('\n');
}
