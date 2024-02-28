#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


/**
 * execute - executes command
 * @command: string command
 * @name: program name
 *
 * Return: nothing
 */
void execute(char *command, char *name)
{
	char **tokens;
	int status;

	tokens = parse_command_line(command);
	status = execute_command(tokens, name);
	if (status != -1)
	{
		perror(name);
	}
}

/**
 * execute_command - executes user command
 * @command: user command in tokens
 * @name: name of program
 *
 * Return: int
 */
int execute_command(char **command, char *name)
{
	pid_t pid;
	int status;

	char *path_to_command = get_command_file(command[0]);

	if (!path_to_command)
		return (0);

	pid = fork();
	if (pid == -1)
		return (0);

	if (pid == 0)
	{
		if (execve(path_to_command, command, environ) == -1)
		{
			perror(name);
			/* free(str); */
			/* free(path_to_command); */
			/* free(command); */
		}
		exit(EXIT_FAILURE);
	}
	waitpid(pid, &status, WUNTRACED);
	free(path_to_command);
	return (-1);
}

/**
 * get_command_file - command file
 * @_command_name: command name
 *
 * Return: path to command file
 */
char *get_command_file(char *_command_name)
{
	char *command_name;

	command_name = malloc(sizeof(char) * (strlen(_command_name) + 1));
	strcpy(command_name, _command_name);
	return (command_name);
}
