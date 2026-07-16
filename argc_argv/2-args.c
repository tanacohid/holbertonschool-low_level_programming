#include <stdio.h>
/**
 * main - affiche le nom de la commande
 * @argv: tableau du nombre de programe
 * @argc: nombre total d argument
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);
	return (0);
}
