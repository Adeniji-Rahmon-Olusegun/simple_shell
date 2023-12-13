#include "main.h"

/**
 * _strdup_for_sshell - returns pointer that points to a new
 * string in a new allocated memory.
 * @str: string
 * Return: pointer
 */

char *_strdup_for_sshell(char *str)
{
	char *ptr_strcpy;
	int i, str_len = 0;

	if (str == NULL)
	{
		return (NULL);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		str_len++;
	}

	if ((sizeof(char) * (str_len + 1)) < (size_t) (str_len))
	{
		return (NULL);
	}

	ptr_strcpy = (char *)malloc(sizeof(char) * (str_len + 1));

	if (ptr_strcpy == NULL)
	{
		return (NULL);
	}

	i = 0;

	while (str[i] != '\0')
	{
		*(ptr_strcpy + i) = str[i];
		i++;
	}

	ptr_strcpy[i] = '\0';

	return (ptr_strcpy);
}
