#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction
 *
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack && (*stack)->next)
	{
		int sum = (*stack)->n + (*stack)->next->n;
		pop(stack, line_number);
		(*stack)->n = sum;
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * nop - Doesn't do anything
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction
 *
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
