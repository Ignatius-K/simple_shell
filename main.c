#include "main.h"

/**
 * main - entry
 * @agc: argument count
 * @ags: arguments
 *
 * Return: int
 */
int main(int agc, char **ags)
{
	if (isatty(STDIN_FILENO) == 1)
		interact_mode(ags[agc - 1]);
	else
		non_interact_mode(ags[agc - 1]);
	return (0);
}


/**
 * non_interact_mode - none interactive mode
 * @name: prog name
 * Return: nothing
 */
void non_interact_mode(char *name)
{
	char *input;
	char **ags;
	int status;

	while (1)
	{
		write(0, "$ ", 2);
		input = get_input();
		ags = get_tokens(input);
		status = exec_command(ags, name);
		free(input);
		free(ags);
		if (status >= 0)
		{
			exit(status);
		} else
			continue;
	}
}


/**
 * interact_mode - interactive mode
 * @name: program name
 *
 * Return: nothing
 */
void interact_mode(char *name)
{
	char *input;
	char **ags;
	int status;

	while (1)
	{
		write(0, "$ ", 2);
		input = get_input();
		ags = get_tokens(input);
		status = exec_command(ags, name);
		free(input);
		free(ags);
		if (status >= 0)
		{
			exit(status);
		} else
		{
			continue;
		}
	}
}
