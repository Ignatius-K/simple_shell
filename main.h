#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

#include <errno.h>

#include <stdlib.h>

#include <sys/wait.h>

#include <string.h>

#include <fcntl.h>

#include <sys/types.h>

#include <unistd.h>

#include <sys/stat.h>

#include <limits.h>

#define DELIM " \n\t\r\a\""

extern char **environ;

void interact_mode(char *name);

void non_interact_mode(char *name);

int _cd(char **ags);

char *read_line(void);

char **get_tokens(char *cmd);

int _env(char **ags);

int handle_exit(char **ags);

int exec_command(char **agv, char *cmd);

int s_call(char **ags, char *cmd);

int access_command(char *path, char **ags);

char *get_input(void);

#endif /* MAIN_H */
