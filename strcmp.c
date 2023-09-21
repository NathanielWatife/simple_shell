#include "shell.h"

/**
 *_strcmp - program thisgs
 *Result: always return 0
 *@s1: variable de entrada
 *@s2: entrada source
 *Return: value depending on function
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int c = 1;
	int resultado = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && c == 1)
	{
		resultado = s1[i] - s2[i];
		if (resultado == 0)
			i++;
		else
			c = 0;

	}
return (resultado);
}
