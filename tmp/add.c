#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 *
 * @stack: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	stack_t *second = top->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_monty_data(&monty_data);
		exit(EXIT_FAILURE);
	}
	second->n += top->n;
	*stack = second;
	free(top);
}
