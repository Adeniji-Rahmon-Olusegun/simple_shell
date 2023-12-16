#include "main.h"

/**
 * sshell_non_interactive_mode - operates simple shell
 * in non interactive mode
 *
 * @file_path: path to file
 * @env: environment variables
 * @arg: name of executable file
 *
 * Return: void
 */

void sshell_non_interactive_mode(char *file_path, char **env, char *arg)
{
	int file_descriptor;
	size_t cmd_line_len;
	ssize_t byte_read;
	char buffer[1024];
	char **string_vector;

	file_descriptor = open(file_path, O_RDONLY);

	if (file_descriptor == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	while ((byte_read = read(file_descriptor, buffer, 1024)))
	{
		buffer[byte_read] = '\0';

		cmd_line_len = _strlen_for_sshell(buffer);

		if (cmd_line_len > 0 && buffer[cmd_line_len - 1] == '\n')
		{
			buffer[cmd_line_len - 1] = '\0';
		}

		string_vector = tokenize_cmd_first_string(buffer, " \t\n", arg);

		if (string_vector[0] != NULL)
		{
			execute_command_line(string_vector, env, arg);
		}

		if (byte_read == -1)
			perror("Error");
		close(file_descriptor);
	}
}
