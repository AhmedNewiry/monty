#include "monty.h"
/**
 * push-  a function that adds a node at the beginning of a stack
 * @head: double pointer to the head of the stack
 * @n: the data to be added
 * @line_number: instruction line number
 */

void push(stack_t **head, char *n, unsigned int line_number)
{
	stack_t *new_node;
	int num_idx = 0, num_ed;

	if (!n)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (n[num_idx] != '\0')
	{
		if (n[0] == '-' && num_idx == 0)
		{
			num_idx++;
			continue;
		}
		if (!isdigit(n[num_idx]))
		{
			fprintf(stderr, "L%d: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		num_idx++;
	}
	num_ed = atoi(n);
	new_node = malloc(sizeof(new_node));
	if (new_node)
	{
		new_node->n = num_ed;
		new_node->prev = NULL;
		new_node->next = *head;
		if (*head != NULL)
		{

			(*(head))->prev = new_node;
		}
		*head = new_node;
	}
	else
	{
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	}
}
