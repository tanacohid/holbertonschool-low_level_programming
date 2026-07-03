#include "main.h"

/**
* print_rev - prints a string in reverse
* @s: pointer to the string
*/

void reverse_array(int *a, int n);
{
	int debut;
	int fin;
	char temp;

	debut = 0;
	fin = n - 1;

	while (debut < fin)
	{
		temp = a[debut];
		a[debut] = a[fin];
		a[fin] = temp;

		debut++;
		fin--;
	}
}
