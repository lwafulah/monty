#include "monty.h"

/**
 * push_opcode - pushes an element to the stack
 * @stack: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void push_opcode(stack_t **stack, unsigned int line_number)
{
	int n, j;
	MontyData monty_data;
	stack_t *new_node = malloc(sizeof(stack_t));
	monty_data.buffer = NULL;

	if (!monty_data.buffer)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_monty_data(&monty_data);
		exit(EXIT_FAILURE);
	}
	for (j = 0; monty_data.buffer[j] != '\0'; j++)
	{
		if (!isdigit(monty_data.buffer[j]) && monty_data.buffer[j] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_monty_data(&monty_data);
			exit(EXIT_FAILURE);
		}
	}
	n = atoi(monty_data.buffer);

	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		free_monty_data(&monty_data);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
