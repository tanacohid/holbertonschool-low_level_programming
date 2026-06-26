#include "main.h"

/**
* _islower - betty je te hais
* @c: c letter to check
* Return: 1 if lowercase lettre
*/
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	return (0);
}
