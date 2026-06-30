#include "main.h"
#include <stdio.h>
/**
* swap_int - to beat or not to beat
* @a: font l'amour a la plage
* @b: font l'amour a la plage
*/
void swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
