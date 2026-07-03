#include "main.h"

/**
 * leet - encodes a string into 1337
 * @a: pointer to the string
 *
 * Return: pointer to the string
 */
char *leet(char *a)
{
	int i;
	int j;
	char letters[] = "aAeEoOtTlL";
	char numbers[] = "4433007711";

	i = 0;

	while (a[i] != '\0')
	{
		j = 0;

		while (letters[j] != '\0')
		{
			if (a[i] == letters[j])
				a[i] = numbers[j];
			j++;
		}
		i++;
	}

	return (a);
}
