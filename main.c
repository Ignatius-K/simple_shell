#include "main.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - entry to the program
 * @argc: number of args
 * @argv: arguments
 *
 * Return: int
 */
int main(int argc, char **argv)
{
	int fd;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror(argv[0]);
			return (EXIT_FAILURE);
		}
		non_interactive_mode(argv[0], fd);
	}
	else
	{
		interactive_mode(argv[0]);
	}
	return (EXIT_SUCCESS);
}

/**
 * interactive_mode - handles interactive mode
 * @name: name of program
 *
 * Return: nothing
 */
void interactive_mode(char *name)
{
	char *line_ptr = NULL;
	size_t n = 0;
	char **tokens;

	printf("$ ");
	while (getline(&line_ptr, &n, stdin) != -1)
	{
		tokens = parse_command_line(line_ptr);
		if (tokens != NULL)
		{
			execute_command(tokens, name, line_ptr);
			free(tokens);
		}
		printf("$ ");
	}
	free(line_ptr);
}


/**
 * non_interactive_mode - handles non-interactive
 * @name: name of program
 * @fd: file descriptor
 *
 * Return: nothing
 */
void non_interactive_mode(char *name, int fd)
{
	char *line_ptr = NULL;
	size_t n = 0;
	char **tokens;
	FILE *fp = fdopen(fd, "r");

	while (getline(&line_ptr, &n, fp) != -1)
	{
		tokens = parse_command_line(line_ptr);
		if (tokens != NULL)
		{
			execute_command(tokens, name, line_ptr);
			free(tokens);
		}
	}
	free(line_ptr);
	close(fd);
	fclose(fp);
}
