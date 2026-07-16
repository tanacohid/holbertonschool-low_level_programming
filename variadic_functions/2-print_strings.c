#include "variadic_functions.h"

/**
 * print_numbers - print tout les argument va_list
 * @separator: separt deux argument de va_list
 * @n: le nombre d'argument de va_list
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned char i;
	char *t;

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

		t = va_arg(args, *char)
		if (t == NULL)
			t = "";

		printf("%s%s", va_arg(args, char *), separator);
	}
	va_end(args);
	printf("\n");
}
