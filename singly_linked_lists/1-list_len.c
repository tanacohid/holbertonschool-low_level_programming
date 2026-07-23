#include "lists.h"
#include <stdio.h>

/**
 * list_len - prints all the elements of a list_t list
 * @h: pointer to the first node
 *
 * Return: the number of nodes
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}
