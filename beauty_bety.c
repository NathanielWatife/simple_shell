#include <stdio.h>

/*
 * A well indented code that satisfy betty
 * Necessary steps where taken
 */

int main(void)
{
/*
 * Declare a variable to store the user's name.
 */
	char name[100];

/*
 * Prompt the user for their name.
 */
	printf("Enter your name: ");
	scanf("%s", name);
/*
 * Greet the user by name.
 */
	printf("Hello, %s!\n", name);
	return (0);
}

