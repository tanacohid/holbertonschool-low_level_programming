#include "main.h"

/**
* times_table - no more
*
* Return: Always 0.
*/
void times_table(void)
{
	int n;
	int t;
	int p;

	p = 0;

	for (n = 0; n < 10; n++)
	{
		for (t = 0; t < 10; t++)
		{
			(p = t * n);
			if	(p >= 10)
				_putchar((p / 10) + '0');

			_putchar((p % 10) + '0');

			if (!(t >= 9))
			{
				_putchar(',');
				_putchar(' ');

				if	((t + 1) * n < 10)
					_putchar(' ');
			}
		}
		_putchar('\n');
	}
}
