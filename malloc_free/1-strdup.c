#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
 char *_strdup(char *str)
{
    int i = 0;
    char *t;

    if (sizeof(*str) == NULL)
    {
        return (NULL);
    }
    for (i = 0; str[i] != '\0'; i++)
    {}

    t = malloc(i);

    if (t == NULL)
	{
        return (NULL);
    }

    for (i = 0; str[i] != '\0'; i++)
    {
        t[i] = str[i];
    }
    return (t);
}
