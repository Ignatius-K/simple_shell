#include "main.h"

/**
 * exec_command - executes command
 * @ags: arguments
 * @name: prog name
 *
 * Return: status
 */
int exec_command(char **ags, char *name)
{
	unsigned long int index;
	char *built_ins[] = {
		"exit",
		"env",
		"cd"
	};
	int (*built_in_funct[])(char **) = {
		&handle_exit,
		&_env,
		&_cd
	};

	if (!ags)
	{
		return (-1);
	}

	for (index = 0; index < sizeof(built_ins) / sizeof(char *); index++)
	{
		if (strcmp(ags[0], built_ins[index]) == 0)
		{
			return ((*built_in_funct[index])(ags));
		}
	}
	return (s_call(ags, name));
}


/**
 * handle_exec_cmd - handles cmd Execution
 * @cmd_ags: command tokens
 *
 * Return: nothing
 */
void handle_exec_cmd(char **cmd_ags)
{
	execvp(cmd_ags[0], cmd_ags);
	perror("Execution error");
	exit(EXIT_FAILURE);
}


/**
 * access_command - gets the command
 * @path: path to command
 * @ags: arguments
 *
 * Return: int
 */
int access_command(char *path, char **ags)
{

	pid_t pid;
	int status;
	int process_status;
	pid_t err_pid;

	pid = fork();
	if (pid == 0)
	{
		process_status = execve(path, ags, environ);
		if (process_status == -1)
		{
			return (-1);
		}
	} else if (pid > 0)
	{
		err_pid = waitpid(pid, &status, WUNTRACED);
		if (err_pid == -1)
		{
			perror("Child process error");
			return (-1);
		}
	} else
	{
		perror("Fork error");
		return (-1);
	}
	return (-1);
}


/**
 * exec_cmd - calls the sys execve
 * @cmd_ags: arguments
 *
 * Return: nothing
 */
void exec_cmd(char **cmd_ags)
{
	execvp(cmd_ags[0], cmd_ags);
	perror("Eecution error");
	exit(EXIT_FAILURE);
}

