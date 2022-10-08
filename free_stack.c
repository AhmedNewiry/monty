#include "monty.h"
/**
 * free_stack - a function that frees a linked list
 * @head: a pointer to the head of a linked list
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head;
		free(temp);
		head = head->next;
	}
}
