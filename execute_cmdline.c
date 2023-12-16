#include "main.h"

/**
 * execute_command_line - executes a command passed at
 * the commandline
 *
 * @arg_string: executable file name
 * @env: environment variable
 * @arg: name of executable file
 *
 * Return: void
 */

void execute_command_line(char **arg_string, char **env, char *arg)
{
	int wait_sts;
	pid_t fork_var;

	fork_var = fork();

	if (fork_var == 0)
	{
		if (execve(arg_string[0], arg_string, env) == -1)
		{
			perror(arg);
			exit(EXIT_FAILURE);
		}
	}
	else if (fork_var == -1)
		perror("Error");
	else
	{
		do {
			waitpid(fork_var, &wait_sts, WUNTRACED);
		} while (!WIFEXITED(wait_sts) && !WIFSIGNALED(wait_sts));

	}
}
