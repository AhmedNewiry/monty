#include "monty.h"
/**
 * stack_len-  a function that returns the number of elements in a linked
 * @h: pointer to the linked list head
 * Return: the length of the linked list
 */


size_t stack_len(const stack_t *h)
i{
	int i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}

	return (i);

}
