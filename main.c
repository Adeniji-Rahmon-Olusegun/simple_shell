#include "main.h"

/**
 * main - acts as a simple shell
 *
 * @argc: argument count
 * @argv: argument vector
 * @env: environmental variables
 *
 * Return: 0 on sucess
 */

int main(__attribute__((unused)) int argc, char **argv, char **env)
{
	if (isatty(STDIN_FILENO))
	{
		sshell_interactive_mode(env, argv[0]);
	}
	else
	{
		sshell_non_interactive_mode(argv[1], env, argv[0]);
	}

	return (0);
}

