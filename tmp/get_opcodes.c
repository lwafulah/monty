#include "monty.h"

/**
 * _stack - sets the format fo the data to a stack (LIFO)
 *
 * @stack: head of the linked list
 * @line_number: line number;
 * Return: no return
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	.lifo = 1;


/**
 * get_opcodes - selects the correct opcode to perform
 *
 * @opc: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */

void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
        instruction_t instruct[] = {
                {"push", _push},
                {"pall", _pall},
                {"pint", _pint},
                {"pop", _pop},
                {"swap", _swap},
                {"stack", _stack},
                {"add", _add},
                {"nop", _nop},
                {NULL, NULL}
        };
        int i;

        for (i = 0; instruct[i].opcode; i++)
        {
                if (strcmp(instruct[i].opcode, opc) == 0)
                        break;
        }

        return (instruct[i].f);
}
