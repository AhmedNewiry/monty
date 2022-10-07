#include "monty.h"
/**
 * pint- a function that prints top element of the stack
 * @h: double pointer to the linked list head
 * @line_number: instruction line number
 */


void pint(stack_t **h, unsigned int line_number)
{
	stack_t *temp = *h;

	if (*h == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (temp)
	{
		printf("%i\n", temp->n);
		break;
	}
}
