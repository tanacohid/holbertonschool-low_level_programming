#include <unistd.h>
#include "main.h"
#include <stdio.h>

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
