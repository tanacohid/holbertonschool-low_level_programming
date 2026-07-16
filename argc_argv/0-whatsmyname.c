#include <stdio.h>
/**
 * main - affiche le nom de la commande
 * @argv: tableau du nombre de programe
 * @argc: nombre total d argument
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	(void)argc;
	printf("%c", argv[0]);
	return (0);
}
