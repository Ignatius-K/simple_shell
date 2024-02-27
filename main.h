#ifndef MAIN_H
#define MAIN_H

#include <bits/types/stack_t.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>

extern char **environ;

char **parse_command_line(char *);

int execute_command(char **command, char *str);

char *get_command_file(char *path);

size_t count_tokens(char *str, char *delim);

char **tokenize(char *str, char *delim);

char **get_tokens(char *str, char *delim, int number_of_tokens);

#endif /* MAIN_H */

