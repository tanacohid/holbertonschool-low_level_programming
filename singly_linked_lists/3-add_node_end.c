#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: address of the head pointer
 * @str: string to duplicate
 *
 * Return: address of the new node, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *current;
	unsigned int i = 0;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	while (str[i] != '\0')
		i++;

	new->len = i;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	current = *head;

	while (current->next != NULL)
		current = current->next;

	current->next = new;

	return (new);
}
