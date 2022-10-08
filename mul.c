#include "monty.h"
/**
 * mul- multiplies the first two element of the stack.
 * @head: double pointer to the linked list head
 * @line_number: instruction line number
 */
void mul(stack_t **head, unsigned int line_number)
{

	int x;

	if (stack_len(*head) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}



	x = (*(head))->next->n * (*(head))->n;
	(*(head))->next->n = x;
	pop(head, line_number);
}
