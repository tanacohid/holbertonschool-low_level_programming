#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * alloc_grid - creates a 2D array of integers
 * @width: number of columns
 * @height: number of rows
 *
 * Return: pointer to the new grid, or NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int i;
	int **tableau;
	int j;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}

	tableau = malloc(sizeof(int) * height);

	if (tableau == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
		tableau[i] = malloc(sizeof(int) * width);
		if (tableau[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(tableau[j]);
			free(tableau);
			return (NULL);
		}
		for (j = 0; j < width; j++)
			tableau[i][j] = 0;
	}
	return (tableau);
}
