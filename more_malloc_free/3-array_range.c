#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array
 * @nmemb: number of elements
 * @size: size of each element
 *
 * Return: pointer to the allocated memory, or NULL on failure
 */
int *array_range(int min, int max)
{
    int total = max - min + 1;

    if (min > max)
        return (NULL);

    total = malloc(total * sizeof(int));

    if (total == NULL)
        return (NULL);
    
    for (int i = 0; i < total; i++)
    {
        total[i] = min + i;
    }
    return (total);
}
