#include "variadic_functions.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned char i;

	if (n == 0)
		return;

	va_start(args, n);


	for (i = 0; i < n; i++)
	{
		if (separator == NULL)
			separator = "";

		printf("%s%d%s", separator, va_arg(args, int), separator);
	}
}
