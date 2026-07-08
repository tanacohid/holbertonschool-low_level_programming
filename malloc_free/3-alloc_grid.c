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

	for (j = 0; j < height; j++)
	{
		tableau[j] = malloc(sizeof(int) * width);
		if (tableau[j] == NULL)
		{
			for (j = 0; j < height; j++)
				free(tableau[j]);
			free(tableau);
			return (NULL);
		}
			for (i = 0; i < width; i++)
				tableau[j][i] = 0;
	}
	return (tableau);
}
