#include <stdio.h>

/**
* main - Entry point
*
* Return: Always 0 (Success)
*/

int main(void)
{
int c;
c = 'a';

	while (c <= 'z')
	{
		if (c == 'e')
			(c = 'f');

		else if (c == 'q')
			(c = 'r');

		putchar(c);
		c++;
	}
		putchar('\n');

	return (0);
}

