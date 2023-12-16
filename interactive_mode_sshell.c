#include "main.h"

/**
 * sshell_interactive_mode - executes the passed commands
 * in an interactive mode
 *
 * @env: environment variables
 * @arg: name of executable file
 * Return void
 */

void sshell_interactive_mode(char **env, char *arg)
{
	size_t malloc_init, cmd_len;
	char *buffer_for_cmd;
	char **string_vector;
	ssize_t bytes_read;

	malloc_init = 0;
	buffer_for_cmd = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "#cisfun$ ", 9);
			fflush(stdout);
		}

		bytes_read = getline(&buffer_for_cmd, &malloc_init, stdin);

		if (bytes_read == -1 || _strcm_for_sshellp(buffer_for_cmd, "exit\n") == 0)
		{
			free(buffer_for_cmd);
			break;
		}

		cmd_len = _strlen_for_sshell(buffer_for_cmd);

		if (cmd_len > 0 && (buffer_for_cmd[cmd_len - 1] == '\n'))
		{
			buffer_for_cmd[cmd_len - 1] = '\0';
		}

		string_vector = tokenize_cmd_first_string(buffer_for_cmd, " \t\n", arg);

		if (string_vector != NULL)
			execute_command_line(string_vector, env, arg);
		else
			continue;
	}
}
