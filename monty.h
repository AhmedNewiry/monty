#ifndef MAIN_H
#define MAIN_H
#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char **mod_strtok(char *buffer, char *delimiter);

/*................stack operations........................*/

void pop(stack_t **head, unsigned int line_number);
void push(stack_t **head, char *n, unsigned int line_number);
void free_stack(stack_t *head);
void print_stack(stack_t **h, unsigned int line_number);
void pint(stack_t **h, unsigned int __attribute__((unused)) line_number);
void swap(stack_t **stack, unsigned int line_number);
size_t dlistint_len(const stack_t *h);
int stack_handler(char *code, stack_t **stack, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void op_handler(stack_t **head, char **op_tokens, unsigned int l_n, int j);
void add(stack_t **head, unsigned int line_number);
size_t stack_len(const stack_t *h);

void mod(stack_t **head, unsigned int line_number);
void _div(stack_t **head, unsigned int line_number);
void mul(stack_t **head, unsigned int line_number);
void sub(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);
void pchar(stack_t **head, unsigned int line_number);

#endif
