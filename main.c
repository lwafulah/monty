#include "monty.h"

#define MAX_LINE_LENGTH 100

int main(int argc, char *argv[])
{
    FILE *file;
    stack_t *stack = NULL;
    char line[MAX_LINE_LENGTH];
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        line_number++;
        execute_opcode(line, &stack, line_number);
    }

    fclose(file);
    free_stack(stack);

    return (0);
}
