#include "monty.h"
/**
 * stack_handler- a function that handles the stack operations
 * @code: the opcode
 * @stack: double pointer to the head of the stack
 * @line_number: the instruction line number
 * Return: 0 if success
 */
int stack_handler(char *code, stack_t **stack, unsigned int line_number)
{
	int fun_idx = 0;

	instruction_t ins_array[] = {
		{"pall", print_stack},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mod", mod},
		{"mul", mul},
		{NULL, NULL}
	};

	while (ins_array[fun_idx].opcode)
	{
		if (strcmp(ins_array[fun_idx].opcode, code) == 0)
		{
			ins_array[fun_idx].f(stack, line_number);
			return (0);

		}

		fun_idx++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, code);
	exit(EXIT_FAILURE);
}
