#include "monty.h"
/**
 * is_numeric - checks if a string is a numeric value
 *
 * @str: string to check
 * Return: 1 if numeric, 0 otherwise
 */
int is_numeric(char *str)
{
	int i;

	if (str == NULL || *str == '\0')
		return 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return 0;
	}

	return 1;
}
/**
 * free_stack - frees a stack
 *
 * @stack: pointer to the head of the stack
 * Return: no return
 */
void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
/**
 * push_stack - pushes a value onto the stack
 *
 * @stack: pointer to the head of the stack
 * @value: value to push
 * Return: no return
 */
void push_stack(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;

	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	else
	{
		new_node->next = NULL;
	}

	*stack = new_node;
}
/**
 * push - pushes an element to the stack
 *
 * @stack: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *arg = strtok(NULL, " \t\n");

	if (!arg || !is_numeric(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);
	push_stack(stack, value);
}

/**
 * pall - prints all values on the stack
 *
 * @stack: head of the linked list
 * @line_number: line numbers
 * Return: no return
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
