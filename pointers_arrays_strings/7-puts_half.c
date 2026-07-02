#include <unistd.h>
#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
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
