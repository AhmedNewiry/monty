#include "monty.h"
/**
 * pop- a function that deletes the stack first node
 * @head: double pointer to the linked list head
 * @line_number: instruction line number
 */
void pop(stack_t **head, unsigned int line_number)
{

	stack_t *temp;


	temp = *head;

	if (!*head || !head)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}


	*head = (*(head))->next;
	if (temp->next)
	{
		(*(head))->prev = NULL;
	}
	free(temp);
}
