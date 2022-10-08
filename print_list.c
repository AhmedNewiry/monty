#include "monty.h"
/**
 * print_stack- a function that prints all data of a linked list
 * @h: double pointer to the linked list head
 * @line_number: instruction line number
 */

void print_stack(stack_t **h, unsigned int __attribute__((unused)) line_number)
{

	stack_t *temp = *h;

	while (temp)
	{
		printf("%i\n", temp->n);
		temp = temp->next;
	}

}
