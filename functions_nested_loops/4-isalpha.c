#include "main.h"

/**
* _isalpha - betty je te hais
* @c: c letter to check
* Return: 1 if lowercase lettre
*/
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}
