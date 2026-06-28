#include "main.h"

/**
 * jack_bauer - prints every minute of the day
 *
 * Return: nothing
 */
void jack_bauer(void)
{
	int min;
	int h;

	min = 00
	h = 00

	for (h = 0; h < 24 ; h++)
	{
		for (min = 0; min < 60 ; min++)
		{
			_putchar((h / 10) + '0');
			_putchar((h % 10) + '0');
			_putchar(':');
			_putchar((m / 10) + '0');
			_putchar((m % 10) + '0');
			_putchar('\n');
		}
	}
}
