#include "main.h"

/**
* print_alphabet - ta race betty
*/

void print_alphabet(void)
{
	int c;

	c = 'a';

	while (c <= 'z')
	{
		_putchar(c);
		c++;
	}
	_putchar('\n');
}
