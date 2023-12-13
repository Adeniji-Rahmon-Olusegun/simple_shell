#include "main.h"

/**
 * get_and_execute_command_line - executes a command
 * with one argument
 *
 * @arg_string: file name
 *
 * Return: void
 */

void get_and_execute_command_line(char *arg_string)
{
	int exec_err;
	char *command;
	char **string_vector;

	while (1)
	{
		command = read_command_line();

		if (fork() != 0)
		{
			wait(NULL);
		}
		else
		{
			string_vector = tokenize_cmd_strings(command, " \n\t");
			exec_err = execve(string_vector[0], string_vector, NULL);

			if (exec_err == -1)
			{
				perror(arg_string);
				exit(EXIT_FAILURE);
			}
		}
	}

}
