#include "main.h"

/**
 * parse_command_line - parses the user input
 * @str: string from stdin
 *
 * Return: parsed command in tokens
 */
char **parse_command_line(char *str)
{
	int str_len;
	char **command;

	str_len = strlen(str);
	str[str_len - 1] = '\0';

	command = tokenize(str, " ");
	return (command);
}


/**
 * tokenize - breaks string into tokens
 * @str: string to breaks
 * @delim: delimitor
 *
 * Return: pointer to token array
 */
char **tokenize(char *str, char *delim)
{
	char **tokenArr = NULL;
	size_t str_len = 0;
	int num_of_tokens = 0;
	char *str_copy = NULL;

	if (!(str && delim))
		return (tokenArr);

	str_len = strlen(str);
	str_copy = malloc(sizeof(char) * (str_len + 1));

	if (str_copy == NULL)
		return (tokenArr);

	strcpy(str_copy, str);

	num_of_tokens = count_tokens(str_copy, delim);
	if (num_of_tokens == 0)
		return (tokenArr);

	tokenArr = get_tokens(str, delim, num_of_tokens);
	free(str_copy);
	return (tokenArr);
}


/**
 * count_tokens - counts the tokens in string
 * @trans: string to counts
 * @delim: delimitor
 *
 * Return: number of tokens
 */
size_t count_tokens(char *trans, char *delim)
{

	size_t num_of_tokens = 0;

	if (!(trans && delim))
		return (0);

	if (strtok(trans, delim))
		num_of_tokens++;
	while (strtok(NULL, delim))
		num_of_tokens++;
	return (num_of_tokens);
}


/**
 * get_tokens - creates tokens based on number
 * @trans: string to breaks
 * @delim: delimitor
 * @number_of_tokens: expected number of tokens
 *
 * Return: pointer to string array
 */
char **get_tokens(char *trans, char *delim, int number_of_tokens)
{

	char **token_arr = NULL;
	size_t index = 0;
	size_t num = number_of_tokens;

	if (!(trans && delim))
		return (0);

	token_arr = malloc(sizeof(char *) * (num + 1));
	if (token_arr == NULL)
		return (NULL);

	token_arr[index] = strtok(trans, delim);

	index++;
	while (index < num)
	{
		token_arr[index] = strtok(NULL, delim);
		index++;
	}

	token_arr[index] = NULL;
	return (token_arr);
}

