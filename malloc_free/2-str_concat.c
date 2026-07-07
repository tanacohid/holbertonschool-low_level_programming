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
char *str_concat(char *s1, char *s2)
{
	int i = 0;
	int p = 0;
	char *t;
	int o;
	int y = 0;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}

	for (i = 0; s1[i] != '\0'; i++)
	{}

	for (p = 0; s2[p] != '\0'; p++)
	{}

	t = malloc(sizeof(char) * (i + p + 1));
	
	if (t == NULL)
	{
		return (NULL);
	}

	for (o = 0; o < i; o++)
	{
		t[o] = s1[o];
	}

	for (; o <= (i + p + 1); o++)
	{
		t[o] = s2[y];
		y++;
	}
	return (t);
}
