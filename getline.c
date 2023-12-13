#include "main.h"

/**
 * read_command_line - reads a commands from stdin
 *
 * Return: void
 */

char *read_command_line(void)
{
	size_t malloc_init;
	ssize_t bytes_read;
	char *buffer_cmdline;

	malloc_init = 0;
	buffer_cmdline = NULL;

	write(STDOUT_FILENO, "#cisfun$ ", 9);

	bytes_read = getline(&buffer_cmdline, &malloc_init, stdin);

	if (bytes_read == -1)
	{
		free(buffer_cmdline);
		exit(1);
	}

	return (buffer_cmdline);
}
