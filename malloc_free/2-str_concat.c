#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * str_concat - concatène deux chaînes de caractères
 * @s1: première chaîne de caractères
 * @s2: deuxième chaîne de caractères
 *
 * Cette fonction alloue un nouvel espace mémoire, copie le contenu
 * de s1 puis celui de s2 dans ce nouvel espace, et ajoute le caractère
 * de fin de chaîne '\0'. Si l'un des paramètres est NULL, il est traité
 * comme une chaîne vide.
 *
 * Return: un pointeur vers la nouvelle chaîne concaténée,
 * ou NULL si l'allocation mémoire échoue.
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
