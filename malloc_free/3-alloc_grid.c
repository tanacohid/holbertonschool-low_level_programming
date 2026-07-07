#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* _strdup - returns a pointer to a newly allocated space in memory
*           containing a copy of the string
* @str: string to duplicate
*
* Return: pointer to the duplicated string, or NULL if it fails
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

	tableau = malloc(sizeoff(int) * height);

	if (tableau == NULL)
	{
		return (NULL);
	}

	for (j = 0; j < height; j++)
	{
		tableau[j] = malloc(sizeoff(int) * width);
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
