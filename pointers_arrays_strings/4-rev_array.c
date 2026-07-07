#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers
 * @a: array of integers
 * @n: number of elements in the array
 */
void reverse_array(int *a, int n)
{
	int debut;
	int fin;
	int temp;

	debut = 0;
	fin = n - 1; // pas obliger, on arrait peu faire (n - 1) a la place de tout les variable fin //

	while (debut < fin)
	{
		temp = a[debut];
		a[debut] = a[fin];
		a[fin] = temp;

		debut++;
		fin--;
	}
}
