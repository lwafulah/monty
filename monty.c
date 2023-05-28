#include "monty.h"
/**
 * start_monty_data - Initializes MontyData structure
 * with the given file descriptor
 * @data: Pointer to the MontyData structure
 * @fd: File descriptor
 */
void start_monty_data(MontyData *data, FILE *fd)
{
	data->buffer = NULL;
	data->lifo = 1;
	data->cont = 1;
	data->arg = NULL;
	data->head = NULL;
	data->fd = fd;
}
/**
 * free_stack - Frees a stack
 * @stack: Pointer to the head of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
/**
 * free_monty_data - Frees memory associated with MontyData structure
 * @data: Pointer to the MontyData structure
 */
void free_monty_data(MontyData *data)
{
	if (data->buffer != NULL)
	{
		free(data->buffer);
		data->buffer = NULL;
	}
	free_stack(data->head);
	fclose(data->fd);
}
