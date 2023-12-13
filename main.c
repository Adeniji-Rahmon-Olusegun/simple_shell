#include "main.h"

/**
 * main - acts as a simple shell
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on sucess
 */

int main(__attribute__((unused)) int argc, char **argv, char **env)
{
	get_and_execute_command_linev(argv[0], env);

	return (0);
}

