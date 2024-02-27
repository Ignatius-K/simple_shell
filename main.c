#include "main.h"
#include <stdio.h>

/**
 * main - entry to the program
 *
 * Return: int
 */
int main(void)
{
	char *line_ptr = NULL;
	size_t n = 0;
	int status;
	char **tokens;

	printf("$ ");
	while (getline(&line_ptr, &n, stdin) != -1)
	{
		tokens = parse_command_line(line_ptr);
		if (tokens != NULL)
		{
			status = execute_command(tokens, line_ptr);
			if (status != 0)
			{
				perror("hsh");
			}
			free(tokens);
		}
		printf("$ ");
	}
	free(line_ptr);
	return (0);
}

