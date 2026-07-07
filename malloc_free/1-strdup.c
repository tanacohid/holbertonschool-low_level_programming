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
char *_strdup(char *str)
{
	int i = 0;
	int p = 0;
	char *t;

	if (str == NULL)
	{
		return (NULL);
	}

	for (i = 0; str[i] != '\0'; i++)
	{}

	t = malloc(sizeof(char) * (i + 1));

	if (t == NULL)
	{
		return (NULL);
	}

	for (p = 0; p <= i ; p++)
	{
		t[p] = str[p];
	}

	return (t);
}
