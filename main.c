#include "main.h"

/**
 * main - entry to the program
 * @argc: number of args
 * @argv: arguments
 *
 * Return: int
 */
int main(int argc __attribute__((unused)), char **argv)
{
	if (isatty(STDIN_FILENO))
	{
		interactive_mode(argv[0]);
	}
	else
	{
		non_interactive_mode(argv[0]);
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

	printf("$ ");
	while (1)
	{
		line_ptr = get_line();
		execute(line_ptr, name);
		free(line_ptr);
		printf("$ ");
	}
	/* free(line_ptr); */
}


/**
 * non_interactive_mode - handles non-interactive
 * @name: name of program
 *
 * Return: nothing
 */
void non_interactive_mode(char *name)
{
	char *line_ptr = NULL;

	while (1)
	{
		line_ptr = get_stream();
		execute(line_ptr, name);
	}
	free(line_ptr);
}




















