#include "main.h"

/**
 * get_input - gets input
 *
 * Return: input
 */
char *get_input(void)
{
	int buffer_size = 1024;
	int i = 0;
	char *input = malloc(sizeof(char) * buffer_size);
	int _char;

	if (input == NULL)
	{
		fprintf(stderr, "Memory alloc error");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		_char = getchar();
		if (_char == EOF)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else if (_char == '\n')
		{
			input[i] = '\0';
			return (input);
		}
		else
		{
			input[i] = _char;
		}
		i++;
		if (i >= buffer_size)
		{
			buffer_size += buffer_size;
			input = realloc(input, buffer_size);
			if (input == NULL)
			{
				fprintf(stderr, "Memory realloc error");
				exit(EXIT_FAILURE);
			}
		}
	}
}


/**
 * get_tokens - gets tokens
 * @input: user input
 *
 * Return: tokens
 */
char **get_tokens(char *input)
{
	int buffer_size = 128;
	int index = 0;
	char *token;
	char **token_arr;

	token_arr = malloc(buffer_size * sizeof(char *));

	if (!token_arr)
	{
		perror("Memory alloc error");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, DELIM);

	while (token != NULL)
	{
		token_arr[index] = token;
		index++;
		if (index >= buffer_size)
		{
			buffer_size += buffer_size;
			token_arr = realloc(token_arr, buffer_size * sizeof(char *));

			if (token_arr == NULL)
			{
				perror("Memory realloc error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIM);
	}
	token_arr[index] = NULL;
	return (token_arr);
}



