#include "monty.h"

/**
 * pint - Prints the value at the top of the stack
 *
 * @stack: Pointer to the top of the stack
 * @line_number: Line number of the instruction
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction
 *
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack)
	{
		stack_t *temp = *stack;

		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction
 *
 */
void swap(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack && (*stack)->next)
	{
		int temp = (*stack)->n;

		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
