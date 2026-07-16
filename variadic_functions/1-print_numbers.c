#include "variadic_functions.h"

/**
 * print_numbers - print tout les argument va_list
 * @separator: separt deux argument de va_list
 * @n: le nombre d'argument de va_list
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned char i;

	if (n == 0)
	{
		printf("\n");
		return;
	}
	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		if (separator == NULL)
			separator = "";

		if (i == n - 1)
			separator = "";

		printf("%d%s", va_arg(args, int), separator);
	}
	printf("\n");
}
