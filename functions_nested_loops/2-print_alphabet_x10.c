#include "main.h"

/**
* print_alphabet_x10 - ta race betty
*/

void print_alphabet_x10(void)
{
	int c;
	int i;

	c = 'a';
	i = '0';

	for (i = 0; i < 10; i++)
	{
		while (c <= 'z')
		{
			_putchar(c);
			c++;
		}
		_putchar('\n');
		(c = 'a');
	}
}
