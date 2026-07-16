#include "function_pointers.h"

/**
 * int_index - searches for an integer using a comparison function
 * @array: pointer to the array of integers
 * @size: number of elements in the array
 * @cmp: pointer to the comparison function
 *
 * Return: the index of the first element for which cmp does not return 0,
 * -1 if no element matches or if an error occurs
 */
int int_index(...)
{
	int i;

	if (size <= 0 || array == NULL || cmp == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}
	return (-1);
}
