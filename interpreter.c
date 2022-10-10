#include "monty.h"

/**
 * main- entery point
 * @argc: number of command line arguments
 * @argv: command line arguments
 * Return: 0 if success
 */


int main(int argc, char **argv)
{
	char *buffer, **op_tokens = NULL;
	stack_t *head = NULL;
	FILE *f_ptr;
	int j = 0;
	size_t n = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f_ptr = fopen(argv[1], "r");
	if (f_ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &n, f_ptr) != -1)
	{
		op_tokens = NULL;
		line_number++;
		if (strcmp(buffer, "\n") == 0)
		{
			continue;
		}
		op_tokens = mod_strtok(buffer, "\n\t\r ");
		j = 0;
		if (!op_tokens[0] || strcmp(op_tokens[0], "#") == 0)
		{
			free(op_optokens);
			continue;
		}
		op_handler(&head, op_tokens, line_number, j);

	}
	fclose(f_ptr), free(buffer), free_stack(head), free(op_tokens);
	return (EXIT_SUCCESS);
}


/**
 * op_handler- handles commands
 * @head: double pointer to thes stack head
 * @op_tokens: line tokens
 * @l_n: instructon line number
 * @j: token indes
 */
void op_handler(stack_t **head, char **op_tokens, unsigned int l_n, int j)
{
	if (strcmp(op_tokens[j], "push") == 0)
	{
		j++;
		push(head, op_tokens[j], l_n);
	}
	else
	{
		stack_handler(op_tokens[j], head, l_n);
	}
	free(op_tokens);
}
