#include "monty.h"
#include "monty.c"
#define _GNU_SOURCE

#define BUFFER_SIZE 1024

/**
 * main - Entry point for the Monty interpreter program
 *
 * @argc: The number of command-line arguments
 * @argv: An array of strings containing the command-line arguments
 *
 * Return: 0 on success, an error code on failure
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	MontyData monty_data;
	char opcode[BUFFER_SIZE];

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	start_monty_data(&monty_data, fd);
	
	while (fgets(opcode, BUFFER_SIZE, fd) != NULL)
	{
		opcode[strcspn(opcode, "\n")] = '\0';
		if (strlen(opcode) > 0)
		{
			void (*f)(stack_t **stack, unsigned int line_number) = get_opcodes(opcode);

			if (f != NULL)
			{
				f(&(monty_data.head), monty_data.cont);
			}
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", monty_data.cont, opcode);
				free_monty_data(&monty_data);
				fclose(fd);
				exit(EXIT_FAILURE);
			}
		}
		monty_data.cont++;
	}

	free_monty_data(&monty_data);
	fclose(fd);

	return (EXIT_SUCCESS);
}
