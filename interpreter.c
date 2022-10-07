#include "monty.h"

/**
 * main- entery point
 * @argc: number of command line arguments
 * @argv: command line arguments
 * Return: 0 if success
 */
int main(int argc, char **argv)
{
	char *buffer, **tok_buff;
	stack_t *head = NULL;
	FILE *f_ptr;
	int i = 0;
	unsigned int line_number = 0;
	long int x;

	if (argc != 2)
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	f_ptr = fopen(argv[1], "r");
	if (f_ptr == NULL)
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	fseek(f_ptr, 0, SEEK_END);
	x = ftell(f_ptr);
	fseek(f_ptr, 0, SEEK_SET);
	buffer = malloc(sizeof(char) * x);
	if (!buffer)
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	fread(buffer, 1, x, f_ptr);
	tok_buff = mod_strtok(buffer, "$\n\t\r ");
	while (tok_buff[i])
	{
		if (strcmp(tok_buff[i], "$") == 0)
			line_number++;
		if (strcmp(tok_buff[i], "push") == 0)
		{
			i++;
			push(&head, tok_buff[i], line_number);
		}
		else
			stack_handler(tok_buff[i], &head, line_number);
		i++;
	}
	printf("%d", line_number);
	fclose(f_ptr), free(tok_buff), free_stack(head);
	return (0);
}
