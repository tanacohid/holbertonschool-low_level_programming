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

	whild(*s != \0)
	{
		a++;
		s++;
	}
	return (a);
}
