#include "monty.h"
/**
 * swap- a function that swaps the top two elements of the stack.
 * @head: double pointer to the linked list head
 * @line_number: instruction line number
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t  *temp2, *temp3;

	if (!head || !*head)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp3 = (*(head))->next->next;
	temp2 = (*(head))->next;
	temp2->prev = NULL;
	temp2->next = *head;
	(*(head))->prev = temp2;
	(*(head))->next = temp3;
	temp3->prev = *head;
	*head = temp2;
}
