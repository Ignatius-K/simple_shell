#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * execute_command - executes user command
 * @command: user command in tokens
 * @str: pointer to user str
 *
 * Return: int
 */
int execute_command(char **command, char *str)
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
		if (execve(path_to_command, command, NULL) == -1)
		{
			free(str);
			free(path_to_command);
			free(command);
			exit(EXIT_FAILURE);
		}
	}
	wait(&status);
	free(path_to_command);
	return (status);
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
