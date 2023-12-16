#include "main.h"

/**
 * tokenize_cmd_first_string - tokenaizes the commandline strings
 *
 * @cmd_string: command line
 * @delimeter: string separating factor
 * @arg: compiled source code arg
 *
 * Return: array of strings
 */

char **tokenize_cmd_first_string(char *cmd_string, char *delimeter, char *arg)
{
	int arg_track;
	char **string_vector;
	char *token, *token2, *src;
	char *cmd_string_dup, *cmd_string_dup2;
	char *buff_c = malloc(sizeof(char) * (_strlen_for_sshell(arg) + 29));

	arg_track = 0;
	_strcpy_for_sshell(buff_c, arg);
	src = ": No such file or directory";
	cmd_string_dup = _strdup_for_sshell(cmd_string);
	cmd_string_dup2 = _strdup_for_sshell(cmd_string);
	token = strtok(cmd_string_dup, delimeter);

	while (token != NULL)
	{
		token = strtok(NULL, delimeter);
		arg_track++;
	}

	if (arg_track >= 2)
	{
		_strcat_for_sshell(buff_c, src);
		_strcat_for_sshell(buff_c, "\n");
		write(STDOUT_FILENO, buff_c,  _strlen_for_sshell(buff_c));
		free(cmd_string_dup);
		free(cmd_string_dup2);
		free(buff_c);
		return (NULL);
	}
	token2 = strtok(cmd_string_dup2, delimeter);
	string_vector = malloc(sizeof(char *) * 2);

	string_vector[0] = malloc(sizeof(char) * _strlen_for_sshell(token2) + 1);
	_strcpy_for_sshell(string_vector[0], token2);
	string_vector[1] = NULL;

	free(cmd_string_dup);
	free(cmd_string_dup2);
	free(buff_c);
	return (string_vector);
}
