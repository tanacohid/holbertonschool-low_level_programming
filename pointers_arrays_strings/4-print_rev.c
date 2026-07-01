#include "main.h"

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