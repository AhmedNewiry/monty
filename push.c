#include "monty.h"
/**
 * push-  a function that adds a node at the beginning of a stack
 * @head: double pointer to the head of the stack
 * @n: the new node data
 * @line_number: the instruction line number
 * Return: pointer to the new node if success or NULL if nots
 */

stack_t *push(stack_t **head, char *n, unsigned int line_number)
{
	stack_t *new_node;

	int num_idx = 0, num_ed;

	while (n[num_idx] != '\0')
	{
		if (!isdigit(n[num_idx]))
		{
			printf("L%d: unknown instruction %s\n", line_number, n);
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
		new_node->next = *head;														if (*head != NULL)
		{
			(*(head))->prev = new_node;
		}
		*head = new_node;
		return (new_node);
	}
	return (NULL);

}
