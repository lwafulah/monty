#include "monty.h"

/**
 * pall_opcode - prints all values on the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number
 * Return: void
 */
void pall_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
