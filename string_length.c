#include "main.h"

/**
 * _strlen_for_sshell - returns the length if a string
 * @s: string
 * Return: length of string
 */

int _strlen_for_sshell(char *s)
{
	int counter = 0;

	while (*s != '\0')
	{
		s++;
		counter++;
	}

	return (counter);
}
