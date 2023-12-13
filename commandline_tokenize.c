#include "main.h"

/**
 * tokenize_cmd_strings - tokenaizes the commandline strings
 *
 * @cmd_string: command line
 * @delimeter: string separating factor
 *
 * Return: array of strings
 */

char **tokenize_cmd_strings(char *cmd_string, char *delimeter)
{
	char *tokens, *tokens1;
	char **string_vector;
	int i, num_tokens_in_cmd;
	char *first_cmd_dup, *second_cmd_dup;

	i = 0;
	num_tokens_in_cmd = 0;

	first_cmd_dup = _strdup_for_sshell(cmd_string);
	second_cmd_dup = _strdup_for_sshell(cmd_string);

	tokens = strtok(first_cmd_dup, delimeter);

	while (tokens != NULL)
	{
		tokens = strtok(NULL, delimeter);
		num_tokens_in_cmd++;
	}

	string_vector = malloc(sizeof(char *) * (num_tokens_in_cmd + 1));

	tokens1 = strtok(second_cmd_dup, delimeter);

	while (tokens1 != NULL)
	{
		string_vector[i] = malloc(sizeof(char) * (_strlen_for_sshell(tokens1) + 1));
		_strcpy_for_sshell(string_vector[i], tokens1);
		tokens1 = strtok(NULL, delimeter);
		i++;
	}
	string_vector[i] = NULL;

	free(first_cmd_dup);
	free(second_cmd_dup);

	return (string_vector);
}
