#include "monty.h"

/**
 * execute_opcode - executes the opcode provided in the input line
 *
 * @line: input line containing the opcode
 * @stack: pointer to the stack
 * @line_number: current line number
 *
 * Return: void
 */
void execute_opcode(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode;

	opcode = strtok(line, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
		return;

	if (strcmp(opcode, "push") == 0)
	{
		push(stack, line_number);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack, line_number);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
		nop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
