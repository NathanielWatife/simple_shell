#include "shell.h"

/**
 * puts_prompt -puts the prompt
 */
void putprompt(void)
{
	_puts(PROMPT);
}
/**
 * _puts - prints a string without a \n
 * @str: string to print
 * Return: void
 */
void _puts(char *str)
{
	unsigned int length;

	length = _strlen(str);
	write(STDOUT_FILENO, str, length);
}

/**
   * _putchar - writes the character c to stdout
   * @c: The character to print
   *
   * Return: On success 1.
   * On error, -1 is returned, and errno is set appropriately.
   */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
  * _puts_int - writes an integer
  * @n: integer
  */
void _puts_int(int n)
{
	unsigned int length = 1, i;
	int temp_n = n;

	while (temp_n / 10)
	{
	length++;
	temp_n /= 10;
	}
	for (i = 0; i < length; i++)
	{
	_putchar((n / (MATH_pow(10, length - i - 1)) + '0'));
	n %= (MATH_pow(10, length - i - 1));
	}
}

/**
  * MATH_pow - exponent fnc
  * @base: base number
  * @exp: exponent number
  * Return: base^exp
  */
int MATH_pow(int base, int exp)
{
	int retint = 1;

	while (exp > 0)
	{
	retint *= base;
	exp--;
	}
	return (retint);
}
