#include "main.h"

/**
 * _strcpy_for_sshell - copies string
 * @dest: buffer
 * @src: pointer
 * Return: pointer to buffer
 */

char *_strcpy_for_sshell(char *dest, char *src)
{
	int counter;

	for (counter = 0; src[counter] != '\0'; counter++)
	{
		dest[counter] = src[counter];
	}

	dest[counter] = '\0';

	return (dest);
}
