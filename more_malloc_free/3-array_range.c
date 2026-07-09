#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: minimum value
 * @max: maximum value
 *
 * Return: pointer to the new array, or NULL on failure
 */
int *array_range(int min, int max)
{
	int *tableau;
	int i, total;

	if (min > max)
		return (NULL);

	total = max - min + 1;

	tableau = malloc(sizeof(int) * total);

	if (tableau == NULL)
		return (NULL);

	for (i = 0; i < total; i++)
		tableau[i] = min + i;

	return (tableau);
}
