#include "main.h"

/**
 * s_call - make execution calls
 * @ags: command ags
 * @name: program name
 *
 * Return: int
 */
int s_call(char **ags, char *name)
{
	char path[1024];
	char *env_path = getenv("PATH");
	char *dir;

	if (access(ags[0], X_OK) == 0)
		return (access_command(ags[0], ags));

	strcpy(path, env_path);

	dir = strtok(path, ":");
	while (dir != NULL)
	{
		char file_path[256];

		strcpy(file_path, dir);
		strcat(file_path, "/");
		strcat(file_path, ags[0]);
		if (access(file_path, X_OK) == 0)
			return (access_command(file_path, ags));
		dir = strtok(NULL, ":");
	}
	perror(name);
	return (-1);
}


/**
 * _cd - builtin like "cd"
 * @ags: command ags
 *
 * Return: int
 */
int _cd(char **ags)
{
	if (ags[1] == NULL)
	{
		fprintf(stderr, "Required arg \"cd\"\n");
	}
	else
	{
		if (chdir(ags[1]) != 0)
			perror("Directory open error\n");
	}
	return (-1);
}


/**
 * _env - built in for "env"
 * @ags: command ags
 *
 * Return: int
 */
int _env(char **ags)
{
	int i = 0;

	ags = environ;
	while (ags[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (-1);
}


/**
 * handle_exit - built in exit
 * @ags: command ags
 *
 * Return: int
 */
int handle_exit(char **ags)
{
	if (ags[1])
		return (atoi(ags[1]));
	else
		return (0);
}

