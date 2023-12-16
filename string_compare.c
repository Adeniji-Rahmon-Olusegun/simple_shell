#include "main.h"

/**
 * _strcmp_for_sshell - compares two strings for difference
 * @s1: first string
 * @s2: second string
 * Return: integer
 */

int _strcmp_for_sshell(char *s1, char *s2)
{
	int i;
	int difference = 0;
	int s1_len = 0, s2_len = 0;

	for (i = 0; s1[i] != '\0'; i++)
	{
		s1_len++;
	}

	for (i = 0; s2[i] != 0; i++)
	{
		s2_len++;
	}

	for (i = 0; s1[i] != '\0'; i++)
	{
		difference += (s1[i] - s2[i]);

		if (difference != 0)
		{
			return (difference);
		}
		else
			continue;
	}

	if (s1_len == s2_len && difference == 0)
		difference = 0;
	return (difference);
}
