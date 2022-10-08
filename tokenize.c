#include "monty.h"
/**
 * mod_strtok- a function that tokenaize the enterd line
 * @buffer: the enterd line
 * @delimiter: the tokens separator
 * Return: array of tokens
 */
char **mod_strtok(char *buffer, char *delimiter)
{
	size_t x;
	char **tokens;

	x = 0;

	if (buffer == NULL)
	{
		return (NULL);
	}
	tokens = malloc(sizeof(char *) * 60);
	if (tokens == NULL)
	{

		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);

	}
	while ((tokens[x] = strtok(buffer, delimiter)) != NULL)
	{
		buffer = NULL;
		x++;
	}
	tokens[x] = NULL;
	return (tokens);
}
