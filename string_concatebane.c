#include "main.h"

/**
 * _strcat_for_sshell - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: pointer
 */

char *_strcat_for_sshell(char *dest, char *src)
{
	int i, j, k;
	int dest_len_tracker = 0;
	int src_len_tracker = 0;

	for (i = 0; dest[i] != '\0'; i++)
	{
		dest_len_tracker++;
	}

	for (j = 0; src[j] != '\0'; j++)
	{
		src_len_tracker++;
	}

	for (k = 0; k <= src_len_tracker; k++)
	{
		dest[k + dest_len_tracker] = src[k];
	}

	return (dest);
}
